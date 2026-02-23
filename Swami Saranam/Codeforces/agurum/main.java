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
    // ── Unicode constants
    ────────────────────────────────────────────────────
    private static final String PRON_NAAN = "\u0BA8\u0BBE\u0BA9\u0BCD";
    private static final String PRON_NAANGAL =
        "\u0BA8\u0BBE\u0B99\u0BCD\u0B95\u0BB3\u0BCD";
    private static final String PRON_AVARGAL =
        "\u0B85\u0BB5\u0BB0\u0BCD\u0B95\u0BB3\u0BCD";
    private static final String PRON_AVAN = "\u0B85\u0BB5\u0BA9\u0BCD";
    private static final String PRON_AVAL = "\u0B85\u0BB5\u0BB3\u0BCD";
    private static final String VEND_EN = "\u0BC7\u0BA9\u0BCD";
    private static final String VEND_OM = "\u0BCB\u0BAE\u0BCD";
    private static final String VEND_AARKKAL =
        "\u0BBE\u0BB0\u0BCD\u0B95\u0BB3\u0BCD";
    private static final String VEND_INAR = "\u0BBF\u0BA9\u0BB0\u0BCD";
    private static final String VEND_AAN = "\u0BBE\u0BA9\u0BCD";
    private static final String VEND_AAL = "\u0BBE\u0BB3\u0BCD";
    private static final String NEND_N = "\u0BA9\u0BCD";
    private static final String NEND_L = "\u0BB3\u0BCD";
    //
    ────────────────────────────────────────────────────────────────────────
    public static void main(String[] args) throws Exception {
        String inputFile = args.length > 0 ? args[0] : "input.txt";
        File f = new File(inputFile);
        if (!f.exists()) {
            System.err.println("Input file not found.");
            System.exit(1);
        }
        // Read all lines; skip blank lines
        List < String > lines = new ArrayList < > ();
        for (String line: Files.readAllLines(f.toPath(), StandardCharsets.UTF_8)) {
            String trimmed = line.trim();
            if (!trimmed.isEmpty()) lines.add(trimmed);
        }
        System.out.println("======================================");
        System.out.println(" TAMIL SEMANTIC ANALYZER ");
        System.out.println("======================================\n");
        System.out.println("Total sentences found : " + lines.size() + "\n");
        // Collect (tree, parser) pairs for each sentence for GUI
        List < ParseTree > trees = new ArrayList < > ();
        List < TamilParser > parsers = new ArrayList < > ();
        List < String > texts = new ArrayList < > ();
        // ── Process each sentence independently
        ──────────────────────────────
        for (int i = 0; i < lines.size(); i++) {
            String sentenceLine = lines.get(i);
            System.out.println("══════════════════════════════════════");
            System.out.printf(" Sentence %d : %s%n", i + 1, sentenceLine);
            System.out.println("══════════════════════════════════════");
            CharStream cs = CharStreams.fromString(sentenceLine);
            TamilLexer lexer = new TamilLexer(cs);
            lexer.removeErrorListeners(); // suppress default noise per sentence
            CommonTokenStream tokens = new CommonTokenStream(lexer);
            tokens.fill();
            // Check for invalid characters
            boolean hasError = false;
            for (Token tok: tokens.getTokens()) {
                if (tok.getType() == TamilLexer.ERROR_CHAR) {
                    System.out.println(" ERROR: Invalid character '" + tok.getText() + "'");
                    hasError = true;
                }
            }
            if (hasError) {
                System.out.println();
                continue;
            }
            TamilParser parser = new TamilParser(tokens);
            parser.removeErrorListeners();
            parser.addErrorListener(new DiagnosticErrorListener());
            TamilParser.FileContext tree = parser.file();
            // Console parse tree
            System.out.println("\n --- Parse Tree (Console) ---");
            printTree(tree, parser, 2);
            // Semantic analysis
            System.out.println("\n --- Semantic Analysis ---");
            printSentence(tree.sentence(), i + 1);
            // Token list
            System.out.println(" --- Tokens ---");
            printTokens(tokens);
            System.out.println();
            trees.add(tree);
            parsers.add(parser);
            texts.add(sentenceLine);
        }
        System.out.println("=========== END OF ANALYSIS ===========");
        // ── Launch one Swing GUI window with all parse trees (tabbed) ────────
        if (!trees.isEmpty()) {
            SwingUtilities.invokeLater(() - > createAndShowGui(trees, parsers, texts));
        }
    }
    // ── Swing GUI: tabbed parse tree viewer
    ──────────────────────────────────
    private static void createAndShowGui(
        List < ParseTree > trees,
        List < TamilParser > parsers,
        List < String > texts) {
        JFrame frame = new JFrame("Tamil Parse Tree Viewer");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new BorderLayout());
        // Title bar
        JLabel title = new JLabel(
            " \uD83C\uDF33 ANTLR4 Parse Tree \u2014 Tamil Semantic Analyzer (" +
            trees.size() + " sentences)",
            SwingConstants.LEFT);
        title.setFont(new Font("Dialog", Font.BOLD, 14));
        title.setForeground(new Color(130, 200, 255));
        title.setBackground(new Color(30, 30, 35));
        title.setOpaque(true);
        title.setBorder(BorderFactory.createEmptyBorder(8, 14, 8, 14));
        // Tabbed pane — one tab per sentence
        JTabbedPane tabs = new JTabbedPane(JTabbedPane.TOP);
        tabs.setFont(new Font("Dialog", Font.PLAIN, 12));
        // Keep reference to the currently visible TreeViewer for zoom buttons
        List < TreeViewer > viewers = new ArrayList < > ();
        for (int i = 0; i < trees.size(); i++) {
            List < String > rules = Arrays.asList(parsers.get(i).getRuleNames());
            TreeViewer view = new TreeViewer(rules, trees.get(i));
            view.setScale(1.2);
            view.setFont(new Font("Dialog", Font.PLAIN, 13));
            viewers.add(view);
            JScrollPane scroll = new JScrollPane(view);
            scroll.getVerticalScrollBar().setUnitIncrement(16);
            scroll.getHorizontalScrollBar().setUnitIncrement(16);
            // Tab label: sentence number + truncated text
            String label = (i + 1) + ". " +
                (texts.get(i).length() > 22 ?
                    texts.get(i).substring(0, 22) + "…" :
                    texts.get(i));
            tabs.addTab(label, scroll);
            tabs.setToolTipTextAt(i, texts.get(i));
        }
        // Control panel
        JPanel controlPanel = new JPanel(new FlowLayout(FlowLayout.LEFT, 8, 6));
        controlPanel.setBackground(new Color(45, 45, 48));
        JButton zoomIn = makeButton("\u002B Zoom In");
        JButton zoomOut = makeButton("\u2212 Zoom Out");
        JButton reset = makeButton("\u21BA Reset");
        JButton fitAll = makeButton("\u26F6 Fit");
        JLabel scaleLbl = new JLabel("Scale: 1.2\u00D7");
        scaleLbl.setForeground(Color.LIGHT_GRAY);
        scaleLbl.setFont(new Font("Monospaced", Font.PLAIN, 12));
        // Helper to get current viewer
        java.util.function.Supplier < TreeViewer > current =
            () - > viewers.get(tabs.getSelectedIndex());
        zoomIn.addActionListener(e - > {
            TreeViewer v = current.get();
            double s = Math.min(v.getScale() + 0.2, 5.0);
            v.setScale(s);
            scaleLbl.setText(String.format("Scale: %.1f\u00D7", s));
            v.revalidate();v.repaint();
        });
        zoomOut.addActionListener(e - > {
            TreeViewer v = current.get();
            double s = Math.max(v.getScale() - 0.2, 0.2);
            v.setScale(s);
            scaleLbl.setText(String.format("Scale: %.1f\u00D7", s));
            v.revalidate();v.repaint();
        });
        reset.addActionListener(e - > {
            TreeViewer v = current.get();
            v.setScale(1.2);
            scaleLbl.setText("Scale: 1.2\u00D7");
            v.revalidate();v.repaint();
        });
        fitAll.addActionListener(e - > {
            int idx = tabs.getSelectedIndex();
            TreeViewer v = viewers.get(idx);
            JScrollPane sp = (JScrollPane) tabs.getComponentAt(idx);
            Dimension view = sp.getViewport().getExtentSize();
            Dimension pref = v.getPreferredSize();
            if (pref.width == 0 || pref.height == 0) return;
            double fit = Math.max(0.2,
                Math.min((double) view.width / pref.width,
                    (double) view.height / pref.height) * 0.92);
            v.setScale(fit);
            scaleLbl.setText(String.format("Scale: %.2f\u00D7", fit));
            v.revalidate();v.repaint();
        });
        // Update scale label when switching tabs
        tabs.addChangeListener(e - > {
            TreeViewer v = current.get();
            scaleLbl.setText(String.format("Scale: %.1f\u00D7", v.getScale()));
        });
        controlPanel.add(zoomIn);
        controlPanel.add(zoomOut);
        controlPanel.add(reset);
        controlPanel.add(fitAll);
        controlPanel.add(Box.createHorizontalStrut(12));
        controlPanel.add(scaleLbl);
        // Status bar
        JLabel statusBar = new JLabel(
            " Click a tab to switch sentences | Scroll to navigate | Use buttons to zoom");
        statusBar.setFont(new Font("Monospaced", Font.PLAIN, 11));
        statusBar.setForeground(new Color(150, 150, 150));
        statusBar.setBackground(new Color(30, 30, 35));
        statusBar.setOpaque(true);
        statusBar.setBorder(BorderFactory.createEmptyBorder(4, 12, 4, 12));
        JPanel southPanel = new JPanel(new BorderLayout());
        southPanel.add(controlPanel, BorderLayout.CENTER);
        southPanel.add(statusBar, BorderLayout.SOUTH);
        frame.add(title, BorderLayout.NORTH);
        frame.add(tabs, BorderLayout.CENTER);
        frame.add(southPanel, BorderLayout.SOUTH);
        frame.setPreferredSize(new Dimension(1100, 720));
        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
    private static JButton makeButton(String text) {
        JButton btn = new JButton(text);
        btn.setFont(new Font("Dialog", Font.PLAIN, 13));
        btn.setFocusPainted(false);
        btn.setBackground(new Color(60, 63, 65));
        btn.setForeground(Color.WHITE);
        btn.setBorder(BorderFactory.createCompoundBorder(
            BorderFactory.createLineBorder(new Color(90, 90, 95)),
            BorderFactory.createEmptyBorder(4, 12, 4, 12)));
        btn.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
        return btn;
    }
    // ── Console parse-tree printer
    ────────────────────────────────────────────
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
    // ── Semantic analysis for one sentence
    ───────────────────────────────────
    private static void printSentence(TamilParser.SentenceContext s, int num) {
        boolean hasError = false;
        for (TamilParser.ClauseContext c: s.clause()) {
            String subject = null, verb = null;
            if (c.subject() != null) {
                subject = c.subject().textVal;
                System.out.println(" Subject : " + c.subject().getText());
            }
            if (c.verbPhrase() != null) {
                verb = c.verbPhrase().verbVal;
                System.out.println(" Verb : " + c.verbPhrase().getText());
            } else {
                System.out.println(" Verb : (absent)");
            }
            if (agreementViolated(subject, verb)) hasError = true;
        }
        System.out.println(" Semantic Status : " +
            (hasError ? "INVALID" : "VALID"));
        System.out.println();
    }
    // ── Token list for one sentence
    ───────────────────────────────────────────
    private static void printTokens(CommonTokenStream tokens) {
        for (Token tok: tokens.getTokens()) {
            if (tok.getType() == Token.EOF) continue;
            String name = TamilLexer.VOCABULARY.getSymbolicName(tok.getType());
            if (name == null) name = String.valueOf(tok.getType());
            System.out.printf(" %-15s -> %s%n", name, tok.getText());
        }
        System.out.println();
    }
    // ── Agreement helpers
    ─────────────────────────────────────────────────────
    private static boolean isPronoun(String s) {
        return PRON_NAAN.equals(s) || PRON_NAANGAL.equals(s) ||
            PRON_AVARGAL.equals(s) || PRON_AVAN.equals(s) || PRON_AVAL.equals(s);
    }
    private static boolean isPluralVerb(String v) {
        return v.endsWith(VEND_AARKKAL) || v.endsWith(VEND_INAR);
    }
    private static boolean agreementViolated(String subject, String verb) {
        if (verb == null) return true;
        if (subject == null) return false;
        if (PRON_NAAN.equals(subject)) return !verb.endsWith(VEND_EN);
        if (PRON_NAANGAL.equals(subject)) return !verb.endsWith(VEND_OM);
        if (PRON_AVARGAL.equals(subject)) return !isPluralVerb(verb);
        if (PRON_AVAN.equals(subject)) return !verb.endsWith(VEND_AAN);
        if (PRON_AVAL.equals(subject)) return !verb.endsWith(VEND_AAL);
        if (!isPronoun(subject) && subject.endsWith(NEND_N)) return !
            verb.endsWith(VEND_AAN);
        if (!isPronoun(subject) && subject.endsWith(NEND_L)) return !
            verb.endsWith(VEND_AAL);
        return false;
    }
}