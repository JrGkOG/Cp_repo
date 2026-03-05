// Generated from Tamil.g4 by ANTLR 4.13.1

    import java.util.*;

import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link TamilParser}.
 */
public interface TamilListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link TamilParser#file}.
	 * @param ctx the parse tree
	 */
	void enterFile(TamilParser.FileContext ctx);
	/**
	 * Exit a parse tree produced by {@link TamilParser#file}.
	 * @param ctx the parse tree
	 */
	void exitFile(TamilParser.FileContext ctx);
	/**
	 * Enter a parse tree produced by {@link TamilParser#sentence}.
	 * @param ctx the parse tree
	 */
	void enterSentence(TamilParser.SentenceContext ctx);
	/**
	 * Exit a parse tree produced by {@link TamilParser#sentence}.
	 * @param ctx the parse tree
	 */
	void exitSentence(TamilParser.SentenceContext ctx);
	/**
	 * Enter a parse tree produced by {@link TamilParser#clause}.
	 * @param ctx the parse tree
	 */
	void enterClause(TamilParser.ClauseContext ctx);
	/**
	 * Exit a parse tree produced by {@link TamilParser#clause}.
	 * @param ctx the parse tree
	 */
	void exitClause(TamilParser.ClauseContext ctx);
	/**
	 * Enter a parse tree produced by {@link TamilParser#validVerbless}.
	 * @param ctx the parse tree
	 */
	void enterValidVerbless(TamilParser.ValidVerblessContext ctx);
	/**
	 * Exit a parse tree produced by {@link TamilParser#validVerbless}.
	 * @param ctx the parse tree
	 */
	void exitValidVerbless(TamilParser.ValidVerblessContext ctx);
	/**
	 * Enter a parse tree produced by {@link TamilParser#subject}.
	 * @param ctx the parse tree
	 */
	void enterSubject(TamilParser.SubjectContext ctx);
	/**
	 * Exit a parse tree produced by {@link TamilParser#subject}.
	 * @param ctx the parse tree
	 */
	void exitSubject(TamilParser.SubjectContext ctx);
	/**
	 * Enter a parse tree produced by {@link TamilParser#object}.
	 * @param ctx the parse tree
	 */
	void enterObject(TamilParser.ObjectContext ctx);
	/**
	 * Exit a parse tree produced by {@link TamilParser#object}.
	 * @param ctx the parse tree
	 */
	void exitObject(TamilParser.ObjectContext ctx);
	/**
	 * Enter a parse tree produced by {@link TamilParser#verbPhrase}.
	 * @param ctx the parse tree
	 */
	void enterVerbPhrase(TamilParser.VerbPhraseContext ctx);
	/**
	 * Exit a parse tree produced by {@link TamilParser#verbPhrase}.
	 * @param ctx the parse tree
	 */
	void exitVerbPhrase(TamilParser.VerbPhraseContext ctx);
	/**
	 * Enter a parse tree produced by {@link TamilParser#nounPhrase}.
	 * @param ctx the parse tree
	 */
	void enterNounPhrase(TamilParser.NounPhraseContext ctx);
	/**
	 * Exit a parse tree produced by {@link TamilParser#nounPhrase}.
	 * @param ctx the parse tree
	 */
	void exitNounPhrase(TamilParser.NounPhraseContext ctx);
	/**
	 * Enter a parse tree produced by {@link TamilParser#adverb}.
	 * @param ctx the parse tree
	 */
	void enterAdverb(TamilParser.AdverbContext ctx);
	/**
	 * Exit a parse tree produced by {@link TamilParser#adverb}.
	 * @param ctx the parse tree
	 */
	void exitAdverb(TamilParser.AdverbContext ctx);
}