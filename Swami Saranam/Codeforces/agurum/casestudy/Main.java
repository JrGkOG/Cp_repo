import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;
import org.antlr.v4.gui.TreeViewer;
import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

public class Main {
    // ── Unicode constants ────────────────────────────────────────────────────
    private static final String PRON_NAAN = "\u0BA8\u0BBE\u0BA9\u0BCD";
    private static final String PRON_NAANGAL = "\u0BA8\u0BBE\u0B99\u0BCD\u0B95\u0BB3\u0BCD";
    private static final String PRON_AVARGAL = "\u0B85\u0BB5\u0BB0\u0BCD\u0B95\u0BB3\u0BCD";
    private static final String PRON_AVAN = "\u0B85\u0BB5\u0BA9\u0BCD";
    private static final String PRON_AVAL = "\u0B85\u0BB5\u0BB3\u0BCD";
    private static final String VEND_EN = "\u0BC7\u0BA9\u0BCD";
    private static final String VEND_OM = "\u0BCB\u0BAE\u0BCD";
    private static final String VEND_AARKKAL = "\u0BBE\u0BB0\u0BCD\u0B95\u0BB3\u0BCD";
    private static final String VEND_INAR = "\u0BBF\u0BA9\u0BB0\u0BCD";
    private static final String VEND_AAN = "\u0BBE\u0BA9\u0BCD";
    private static final String VEND_AAL = "\u0BBE\u0BB3\u0BCD";
    private static final String NEND_N = "\u0BA9\u0BCD";
    private static final String NEND_L = "\u0BB3\u0BCD";

    public static void main(String[] args) throws Exception {
        String inputFile = args.length > 0 ? args[0] : "input.txt";
        File f = new File(inputFile);
        if (!f.exists()) {
            System.err.println("Input file not found.");
            System.exit(1);
        }

        List<String> lines = new ArrayList<>();
        for (String line : Files.readAllLines(f.toPath(), StandardCharsets.UTF_8)) {
            String trimmed = line.trim();
            if (!trimmed.isEmpty()) lines.add(trimmed);
        }

        System.out.println("======================================");
        System.out.println(" TAMIL SEMANTIC ANALYZER ");
        System.out.println("======================================\n");

        List<ParseTree> trees = new ArrayList<>();
        List<TamilParser> parsers = new ArrayList<>();
        List<String> texts = new ArrayList<>();

        for (int i = 0; i < lines.size(); i++) {
            String sentenceLine = lines.get(i);
            System.out.println("══════════════════════════════════════");
            System.out.printf(" Sentence %d : %s%n", i + 1, sentenceLine);
            System.out.println("══════════════════════════════════════");

            CharStream cs = CharStreams.fromString(sentenceLine);
            TamilLexer lexer = new TamilLexer(cs);
            lexer.removeErrorListeners(); 
            CommonTokenStream tokens = new CommonTokenStream(lexer);
            tokens.fill();

            TamilParser parser = new TamilParser(tokens);
            parser.removeErrorListeners();
            parser.addErrorListener(new DiagnosticErrorListener());
            TamilParser.FileContext tree = parser.file();

            System.out.println("\n --- Parse Tree (Console) ---");
            printTree(tree, parser, 2);

            System.out.println("\n --- Semantic Analysis ---");
            printSentence(tree.sentence());

            System.out.println(" --- Tokens ---");
            printTokens(tokens);

            trees.add(tree);
            parsers.add(parser);
            texts.add(sentenceLine);
        }
        
        if (!trees.isEmpty()) {
            SwingUtilities.invokeLater(() -> createAndShowGui(trees, parsers, texts));
        }
    }

    // ── Semantic analysis for one sentence ───────────────────────────────────
    private static void printSentence(TamilParser.SentenceContext s) {
        if (s == null) return;
        boolean hasError = false;

        // 1. Check if it's an explicitly allowed verbless phrase ("அழகான மலர்", "எப்படி")
        if (s.validVerbless() != null) {
            System.out.println(" Phrase Type : Valid Verbless Phrase");
            System.out.println(" Verb        : (absent - Structurally Valid in Tamil)");
            System.out.println(" Semantic Status : VALID\n");
            return;
        }

        // 2. Otherwise, check standard clauses (Must have verbs)
        if (s.clause() != null && !s.clause().isEmpty()) {
            for (TamilParser.ClauseContext c : s.clause()) {
                String subject = null, verb = null;
                
                if (c.subject() != null) {
                    subject = c.subject().getText();
                    System.out.println(" Subject : " + subject);
                }
                
                if (c.verbPhrase() != null) {
                    verb = c.verbPhrase().getText();
                    System.out.println(" Verb : " + verb);
                } else {
                    // Because grammar requires a verb in a clause, a missing verb here is a structural violation!
                    System.out.println(" Verb : (MISSING - INVALID STRUCTURE)");
                    hasError = true;
                }
                
                if (verb != null && subject != null && agreementViolated(subject, verb)) {
                    hasError = true; // Flag if verb endings don't match the subject
                }
            }
        }
        
        System.out.println(" Semantic Status : " + (hasError ? "INVALID (Missing Verb or Agreement Error)" : "VALID"));
        System.out.println();
    }

    private static void printTokens(CommonTokenStream tokens) {
        for (Token tok : tokens.getTokens()) {
            if (tok.getType() == Token.EOF) continue;
            String name = TamilLexer.VOCABULARY.getSymbolicName(tok.getType());
            if (name == null) name = String.valueOf(tok.getType());
            System.out.printf(" %-15s -> %s%n", name, tok.getText());
        }
        System.out.println();
    }

    private static boolean isPronoun(String s) {
        return PRON_NAAN.equals(s) || PRON_NAANGAL.equals(s) ||
                PRON_AVARGAL.equals(s) || PRON_AVAN.equals(s) || PRON_AVAL.equals(s);
    }

    private static boolean isPluralVerb(String v) {
        return v.endsWith(VEND_AARKKAL) || v.endsWith(VEND_INAR);
    }

    private static boolean agreementViolated(String subject, String verb) {
        if (verb == null || subject == null) return false;
        
        if (PRON_NAAN.equals(subject)) return !verb.endsWith(VEND_EN);
        if (PRON_NAANGAL.equals(subject)) return !verb.endsWith(VEND_OM);
        if (PRON_AVARGAL.equals(subject)) return !isPluralVerb(verb);
        if (PRON_AVAN.equals(subject)) return !verb.endsWith(VEND_AAN);
        if (PRON_AVAL.equals(subject)) return !verb.endsWith(VEND_AAL);
        
        if (!isPronoun(subject) && subject.endsWith(NEND_N)) return !verb.endsWith(VEND_AAN);
        if (!isPronoun(subject) && subject.endsWith(NEND_L)) return !verb.endsWith(VEND_AAL);
        return false;
    }

    private static void printTree(ParseTree node, Parser parser, int depth) {
        String indent = " ".repeat(depth);
        if (node instanceof TerminalNode) {
            TerminalNode tn = (TerminalNode) node;
            Token tok = tn.getSymbol();
            if (tok.getType() == Token.EOF) return;
            String name = TamilLexer.VOCABULARY.getSymbolicName(tok.getType());
            if (name == null) name = String.valueOf(tok.getType());
            System.out.println(indent + name + ": '" + tok.getText() + "'");
        } else {
            String ruleName = parser.getRuleNames()[((RuleContext) node).getRuleIndex()];
            System.out.println(indent + ruleName);
            for (int i = 0; i < node.getChildCount(); i++)
                printTree(node.getChild(i), parser, depth + 1);
        }
    }

    private static void createAndShowGui(List<ParseTree> trees, List<TamilParser> parsers, List<String> texts) {
        JFrame frame = new JFrame("Tamil Parse Tree Viewer");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new BorderLayout());

        JTabbedPane tabs = new JTabbedPane(JTabbedPane.TOP);
        List<TreeViewer> viewers = new ArrayList<>();
        
        for (int i = 0; i < trees.size(); i++) {
            List<String> rules = Arrays.asList(parsers.get(i).getRuleNames());
            TreeViewer view = new TreeViewer(rules, trees.get(i));
            view.setScale(1.2);
            viewers.add(view);

            JScrollPane scroll = new JScrollPane(view);
            String label = (i + 1) + ". " + (texts.get(i).length() > 22 ? texts.get(i).substring(0, 22) + "…" : texts.get(i));
            tabs.addTab(label, scroll);
        }

        JPanel controlPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        JButton fitAll = new JButton("Fit Screen");
        fitAll.addActionListener(e -> {
            int idx = tabs.getSelectedIndex();
            TreeViewer v = viewers.get(idx);
            JScrollPane sp = (JScrollPane) tabs.getComponentAt(idx);
            Dimension viewSize = sp.getViewport().getExtentSize();
            Dimension prefSize = v.getPreferredSize();
            if (prefSize.width > 0) v.setScale(Math.min((double) viewSize.width / prefSize.width, 1.0));
            v.revalidate(); v.repaint();
        });
        
        controlPanel.add(fitAll);
        frame.add(controlPanel, BorderLayout.NORTH);
        frame.add(tabs, BorderLayout.CENTER);
        frame.setPreferredSize(new Dimension(1100, 720));
        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}