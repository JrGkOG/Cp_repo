// Generated from Tamil.g4 by ANTLR 4.13.1

    import java.util.*;

import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class TamilParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		PRONOUN=1, QUESTION_WORD=2, LINK_WORD=3, POSTPOSITION=4, ADJ=5, ADV=6, 
		ACTION_VERB=7, TAMIL_WORD=8, TAMIL_NUMBER=9, NUMBER=10, QUESTION_MARK=11, 
		PUNCT=12, WS=13, ERROR_CHAR=14;
	public static final int
		RULE_file = 0, RULE_sentence = 1, RULE_clause = 2, RULE_validVerbless = 3, 
		RULE_subject = 4, RULE_object = 5, RULE_verbPhrase = 6, RULE_nounPhrase = 7, 
		RULE_adverb = 8;
	private static String[] makeRuleNames() {
		return new String[] {
			"file", "sentence", "clause", "validVerbless", "subject", "object", "verbPhrase", 
			"nounPhrase", "adverb"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, "'?'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "PRONOUN", "QUESTION_WORD", "LINK_WORD", "POSTPOSITION", "ADJ", 
			"ADV", "ACTION_VERB", "TAMIL_WORD", "TAMIL_NUMBER", "NUMBER", "QUESTION_MARK", 
			"PUNCT", "WS", "ERROR_CHAR"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "Tamil.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }


	    void semanticError(String sentence, String reason) {
	        System.out.println("\n [SEMANTIC ERROR] In phrase: " + sentence);
	        System.out.println("  --> Reason: " + reason);
	    }

	    boolean isFirstPerson(String s) { return "நான்".equals(s); }
	    boolean isFirstPersonPlural(String s) { return "நாங்கள்".equals(s); }
	    boolean isPluralPronoun(String s) { return "அவர்கள்".equals(s); }
	    boolean isMalePronoun(String s) { return "அவன்".equals(s); }
	    boolean isFemalePronoun(String s) { return "அவள்".equals(s); }

	    boolean isPronoun(String s) {
	        return isFirstPerson(s) || isFirstPersonPlural(s) ||
	               isPluralPronoun(s) || isMalePronoun(s) || isFemalePronoun(s);
	    }

	    boolean isMaleNoun(String s) { return !isPronoun(s) && s.endsWith("\u0BA9\u0BCD"); } 
	    boolean isFemaleNoun(String s) { return !isPronoun(s) && s.endsWith("\u0BB3\u0BCD"); }

	    boolean isPluralVerb(String v) { return v.endsWith("\u0BBE\u0BB0\u0BCD\u0B95\u0BB3\u0BCD") || v.endsWith("\u0BBF\u0BA9\u0BB0\u0BCD") || v.endsWith("\u0BBE\u0BB0\u0BCD"); } 
	    boolean isFirstPersonVerb(String v) { return v.endsWith("\u0BC7\u0BA9\u0BCD"); } 
	    boolean isFirstPersonPluralVerb(String v) { return v.endsWith("\u0BCB\u0BAE\u0BCD"); } 
	    boolean isMaleVerb(String v) { return v.endsWith("\u0BBE\u0BA9\u0BCD"); } 
	    boolean isFemaleVerb(String v) { return v.endsWith("\u0BBE\u0BB3\u0BCD"); }

	    void checkAgreement(String subj, String verb, String sentence) {
	        if (verb == null || subj == null) return; 

	        if (isFirstPerson(subj) && !isFirstPersonVerb(verb)) semanticError(sentence, "'நான்' must use verb ending 'ேன்'.");
	        else if (isFirstPersonPlural(subj) && !isFirstPersonPluralVerb(verb)) semanticError(sentence, "'நாங்கள்' must use verb ending 'ோம்'.");
	        else if (isPluralPronoun(subj) && !isPluralVerb(verb)) semanticError(sentence, "Plural subject must use plural verb.");
	        else if (isMalePronoun(subj) && !isMaleVerb(verb)) semanticError(sentence, "'அவன்' must use verb ending 'ான்'.");
	        else if (isFemalePronoun(subj) && !isFemaleVerb(verb)) semanticError(sentence, "'அவள்' must use verb ending 'ாள்'.");
	        else if (isMaleNoun(subj) && !isMaleVerb(verb)) semanticError(sentence, "Masculine noun must use verb ending 'ான்'.");
	        else if (isFemaleNoun(subj) && !isFemaleVerb(verb)) semanticError(sentence, "Feminine noun must use verb ending 'ாள்'.");
	    }

	public TamilParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FileContext extends ParserRuleContext {
		public SentenceContext sentence() {
			return getRuleContext(SentenceContext.class,0);
		}
		public TerminalNode EOF() { return getToken(TamilParser.EOF, 0); }
		public FileContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_file; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof TamilListener ) ((TamilListener)listener).enterFile(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof TamilListener ) ((TamilListener)listener).exitFile(this);
		}
	}

	public final FileContext file() throws RecognitionException {
		FileContext _localctx = new FileContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_file);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(18);
			sentence();
			setState(19);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class SentenceContext extends ParserRuleContext {
		public List<ClauseContext> clause() {
			return getRuleContexts(ClauseContext.class);
		}
		public ClauseContext clause(int i) {
			return getRuleContext(ClauseContext.class,i);
		}
		public List<TerminalNode> LINK_WORD() { return getTokens(TamilParser.LINK_WORD); }
		public TerminalNode LINK_WORD(int i) {
			return getToken(TamilParser.LINK_WORD, i);
		}
		public TerminalNode PUNCT() { return getToken(TamilParser.PUNCT, 0); }
		public TerminalNode QUESTION_MARK() { return getToken(TamilParser.QUESTION_MARK, 0); }
		public ValidVerblessContext validVerbless() {
			return getRuleContext(ValidVerblessContext.class,0);
		}
		public SentenceContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sentence; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof TamilListener ) ((TamilListener)listener).enterSentence(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof TamilListener ) ((TamilListener)listener).exitSentence(this);
		}
	}

	public final SentenceContext sentence() throws RecognitionException {
		SentenceContext _localctx = new SentenceContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_sentence);
		int _la;
		try {
			setState(36);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(21);
				clause();
				setState(26);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==LINK_WORD) {
					{
					{
					setState(22);
					match(LINK_WORD);
					setState(23);
					clause();
					}
					}
					setState(28);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(30);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==QUESTION_MARK || _la==PUNCT) {
					{
					setState(29);
					_la = _input.LA(1);
					if ( !(_la==QUESTION_MARK || _la==PUNCT) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					}
				}

				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(32);
				validVerbless();
				setState(34);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==QUESTION_MARK || _la==PUNCT) {
					{
					setState(33);
					_la = _input.LA(1);
					if ( !(_la==QUESTION_MARK || _la==PUNCT) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					}
				}

				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ClauseContext extends ParserRuleContext {
		public SubjectContext subject;
		public VerbPhraseContext verbPhrase;
		public SubjectContext subject() {
			return getRuleContext(SubjectContext.class,0);
		}
		public VerbPhraseContext verbPhrase() {
			return getRuleContext(VerbPhraseContext.class,0);
		}
		public List<ObjectContext> object() {
			return getRuleContexts(ObjectContext.class);
		}
		public ObjectContext object(int i) {
			return getRuleContext(ObjectContext.class,i);
		}
		public List<AdverbContext> adverb() {
			return getRuleContexts(AdverbContext.class);
		}
		public AdverbContext adverb(int i) {
			return getRuleContext(AdverbContext.class,i);
		}
		public List<TerminalNode> QUESTION_WORD() { return getTokens(TamilParser.QUESTION_WORD); }
		public TerminalNode QUESTION_WORD(int i) {
			return getToken(TamilParser.QUESTION_WORD, i);
		}
		public ClauseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_clause; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof TamilListener ) ((TamilListener)listener).enterClause(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof TamilListener ) ((TamilListener)listener).exitClause(this);
		}
	}

	public final ClauseContext clause() throws RecognitionException {
		ClauseContext _localctx = new ClauseContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_clause);
		int _la;
		try {
			setState(59);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(38);
				((ClauseContext)_localctx).subject = subject();
				setState(44);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 1892L) != 0)) {
					{
					setState(42);
					_errHandler.sync(this);
					switch (_input.LA(1)) {
					case ADJ:
					case TAMIL_WORD:
					case TAMIL_NUMBER:
					case NUMBER:
						{
						setState(39);
						object();
						}
						break;
					case ADV:
						{
						setState(40);
						adverb();
						}
						break;
					case QUESTION_WORD:
						{
						setState(41);
						match(QUESTION_WORD);
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					}
					setState(46);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(47);
				((ClauseContext)_localctx).verbPhrase = verbPhrase();
				 checkAgreement(((ClauseContext)_localctx).subject.textVal, ((ClauseContext)_localctx).verbPhrase.verbVal, _localctx.getText()); 
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(53); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					setState(53);
					_errHandler.sync(this);
					switch (_input.LA(1)) {
					case ADJ:
					case TAMIL_WORD:
					case TAMIL_NUMBER:
					case NUMBER:
						{
						setState(50);
						object();
						}
						break;
					case ADV:
						{
						setState(51);
						adverb();
						}
						break;
					case QUESTION_WORD:
						{
						setState(52);
						match(QUESTION_WORD);
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					}
					setState(55); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & 1892L) != 0) );
				setState(57);
				verbPhrase();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(58);
				verbPhrase();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ValidVerblessContext extends ParserRuleContext {
		public List<TerminalNode> ADJ() { return getTokens(TamilParser.ADJ); }
		public TerminalNode ADJ(int i) {
			return getToken(TamilParser.ADJ, i);
		}
		public List<TerminalNode> TAMIL_WORD() { return getTokens(TamilParser.TAMIL_WORD); }
		public TerminalNode TAMIL_WORD(int i) {
			return getToken(TamilParser.TAMIL_WORD, i);
		}
		public TerminalNode POSTPOSITION() { return getToken(TamilParser.POSTPOSITION, 0); }
		public TerminalNode QUESTION_WORD() { return getToken(TamilParser.QUESTION_WORD, 0); }
		public TerminalNode PRONOUN() { return getToken(TamilParser.PRONOUN, 0); }
		public TerminalNode NUMBER() { return getToken(TamilParser.NUMBER, 0); }
		public ValidVerblessContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_validVerbless; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof TamilListener ) ((TamilListener)listener).enterValidVerbless(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof TamilListener ) ((TamilListener)listener).exitValidVerbless(this);
		}
	}

	public final ValidVerblessContext validVerbless() throws RecognitionException {
		ValidVerblessContext _localctx = new ValidVerblessContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_validVerbless);
		int _la;
		try {
			setState(79);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(64);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==ADJ) {
					{
					{
					setState(61);
					match(ADJ);
					}
					}
					setState(66);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(68); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(67);
					match(TAMIL_WORD);
					}
					}
					setState(70); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==TAMIL_WORD );
				setState(73);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==POSTPOSITION) {
					{
					setState(72);
					match(POSTPOSITION);
					}
				}

				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(75);
				match(QUESTION_WORD);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(76);
				match(PRONOUN);
				setState(77);
				match(NUMBER);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(78);
				match(PRONOUN);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class SubjectContext extends ParserRuleContext {
		public String textVal;
		public Token PRONOUN;
		public Token TAMIL_WORD;
		public TerminalNode PRONOUN() { return getToken(TamilParser.PRONOUN, 0); }
		public List<TerminalNode> ADJ() { return getTokens(TamilParser.ADJ); }
		public TerminalNode ADJ(int i) {
			return getToken(TamilParser.ADJ, i);
		}
		public TerminalNode TAMIL_WORD() { return getToken(TamilParser.TAMIL_WORD, 0); }
		public SubjectContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_subject; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof TamilListener ) ((TamilListener)listener).enterSubject(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof TamilListener ) ((TamilListener)listener).exitSubject(this);
		}
	}

	public final SubjectContext subject() throws RecognitionException {
		SubjectContext _localctx = new SubjectContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_subject);
		int _la;
		try {
			setState(97);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(84);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==ADJ) {
					{
					{
					setState(81);
					match(ADJ);
					}
					}
					setState(86);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(87);
				((SubjectContext)_localctx).PRONOUN = match(PRONOUN);
				 ((SubjectContext)_localctx).textVal =  ((SubjectContext)_localctx).PRONOUN.getText(); 
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(92);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==ADJ) {
					{
					{
					setState(89);
					match(ADJ);
					}
					}
					setState(94);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(95);
				((SubjectContext)_localctx).TAMIL_WORD = match(TAMIL_WORD);
				 ((SubjectContext)_localctx).textVal =  ((SubjectContext)_localctx).TAMIL_WORD.getText(); 
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ObjectContext extends ParserRuleContext {
		public NounPhraseContext nounPhrase() {
			return getRuleContext(NounPhraseContext.class,0);
		}
		public TerminalNode TAMIL_NUMBER() { return getToken(TamilParser.TAMIL_NUMBER, 0); }
		public TerminalNode NUMBER() { return getToken(TamilParser.NUMBER, 0); }
		public ObjectContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_object; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof TamilListener ) ((TamilListener)listener).enterObject(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof TamilListener ) ((TamilListener)listener).exitObject(this);
		}
	}

	public final ObjectContext object() throws RecognitionException {
		ObjectContext _localctx = new ObjectContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_object);
		try {
			setState(102);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ADJ:
			case TAMIL_WORD:
				enterOuterAlt(_localctx, 1);
				{
				setState(99);
				nounPhrase();
				}
				break;
			case TAMIL_NUMBER:
				enterOuterAlt(_localctx, 2);
				{
				setState(100);
				match(TAMIL_NUMBER);
				}
				break;
			case NUMBER:
				enterOuterAlt(_localctx, 3);
				{
				setState(101);
				match(NUMBER);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VerbPhraseContext extends ParserRuleContext {
		public String verbVal;
		public Token ts;
		public TerminalNode ACTION_VERB() { return getToken(TamilParser.ACTION_VERB, 0); }
		public VerbPhraseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_verbPhrase; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof TamilListener ) ((TamilListener)listener).enterVerbPhrase(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof TamilListener ) ((TamilListener)listener).exitVerbPhrase(this);
		}
	}

	public final VerbPhraseContext verbPhrase() throws RecognitionException {
		VerbPhraseContext _localctx = new VerbPhraseContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_verbPhrase);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(104);
			((VerbPhraseContext)_localctx).ts = match(ACTION_VERB);
			 ((VerbPhraseContext)_localctx).verbVal =  ((VerbPhraseContext)_localctx).ts.getText(); 
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class NounPhraseContext extends ParserRuleContext {
		public List<TerminalNode> ADJ() { return getTokens(TamilParser.ADJ); }
		public TerminalNode ADJ(int i) {
			return getToken(TamilParser.ADJ, i);
		}
		public List<TerminalNode> TAMIL_WORD() { return getTokens(TamilParser.TAMIL_WORD); }
		public TerminalNode TAMIL_WORD(int i) {
			return getToken(TamilParser.TAMIL_WORD, i);
		}
		public TerminalNode POSTPOSITION() { return getToken(TamilParser.POSTPOSITION, 0); }
		public NounPhraseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_nounPhrase; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof TamilListener ) ((TamilListener)listener).enterNounPhrase(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof TamilListener ) ((TamilListener)listener).exitNounPhrase(this);
		}
	}

	public final NounPhraseContext nounPhrase() throws RecognitionException {
		NounPhraseContext _localctx = new NounPhraseContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_nounPhrase);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(110);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==ADJ) {
				{
				{
				setState(107);
				match(ADJ);
				}
				}
				setState(112);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(114); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(113);
					match(TAMIL_WORD);
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(116); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,18,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			setState(119);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==POSTPOSITION) {
				{
				setState(118);
				match(POSTPOSITION);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class AdverbContext extends ParserRuleContext {
		public TerminalNode ADV() { return getToken(TamilParser.ADV, 0); }
		public AdverbContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_adverb; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof TamilListener ) ((TamilListener)listener).enterAdverb(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof TamilListener ) ((TamilListener)listener).exitAdverb(this);
		}
	}

	public final AdverbContext adverb() throws RecognitionException {
		AdverbContext _localctx = new AdverbContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_adverb);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(121);
			match(ADV);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\u0004\u0001\u000e|\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0005\u0001\u0019\b\u0001\n\u0001\f\u0001\u001c\t\u0001\u0001"+
		"\u0001\u0003\u0001\u001f\b\u0001\u0001\u0001\u0001\u0001\u0003\u0001#"+
		"\b\u0001\u0003\u0001%\b\u0001\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0005\u0002+\b\u0002\n\u0002\f\u0002.\t\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0004\u00026\b"+
		"\u0002\u000b\u0002\f\u00027\u0001\u0002\u0001\u0002\u0003\u0002<\b\u0002"+
		"\u0001\u0003\u0005\u0003?\b\u0003\n\u0003\f\u0003B\t\u0003\u0001\u0003"+
		"\u0004\u0003E\b\u0003\u000b\u0003\f\u0003F\u0001\u0003\u0003\u0003J\b"+
		"\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0003\u0003P\b"+
		"\u0003\u0001\u0004\u0005\u0004S\b\u0004\n\u0004\f\u0004V\t\u0004\u0001"+
		"\u0004\u0001\u0004\u0001\u0004\u0005\u0004[\b\u0004\n\u0004\f\u0004^\t"+
		"\u0004\u0001\u0004\u0001\u0004\u0003\u0004b\b\u0004\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0003\u0005g\b\u0005\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0007\u0005\u0007m\b\u0007\n\u0007\f\u0007p\t\u0007\u0001"+
		"\u0007\u0004\u0007s\b\u0007\u000b\u0007\f\u0007t\u0001\u0007\u0003\u0007"+
		"x\b\u0007\u0001\b\u0001\b\u0001\b\u0000\u0000\t\u0000\u0002\u0004\u0006"+
		"\b\n\f\u000e\u0010\u0000\u0001\u0001\u0000\u000b\f\u008c\u0000\u0012\u0001"+
		"\u0000\u0000\u0000\u0002$\u0001\u0000\u0000\u0000\u0004;\u0001\u0000\u0000"+
		"\u0000\u0006O\u0001\u0000\u0000\u0000\ba\u0001\u0000\u0000\u0000\nf\u0001"+
		"\u0000\u0000\u0000\fh\u0001\u0000\u0000\u0000\u000en\u0001\u0000\u0000"+
		"\u0000\u0010y\u0001\u0000\u0000\u0000\u0012\u0013\u0003\u0002\u0001\u0000"+
		"\u0013\u0014\u0005\u0000\u0000\u0001\u0014\u0001\u0001\u0000\u0000\u0000"+
		"\u0015\u001a\u0003\u0004\u0002\u0000\u0016\u0017\u0005\u0003\u0000\u0000"+
		"\u0017\u0019\u0003\u0004\u0002\u0000\u0018\u0016\u0001\u0000\u0000\u0000"+
		"\u0019\u001c\u0001\u0000\u0000\u0000\u001a\u0018\u0001\u0000\u0000\u0000"+
		"\u001a\u001b\u0001\u0000\u0000\u0000\u001b\u001e\u0001\u0000\u0000\u0000"+
		"\u001c\u001a\u0001\u0000\u0000\u0000\u001d\u001f\u0007\u0000\u0000\u0000"+
		"\u001e\u001d\u0001\u0000\u0000\u0000\u001e\u001f\u0001\u0000\u0000\u0000"+
		"\u001f%\u0001\u0000\u0000\u0000 \"\u0003\u0006\u0003\u0000!#\u0007\u0000"+
		"\u0000\u0000\"!\u0001\u0000\u0000\u0000\"#\u0001\u0000\u0000\u0000#%\u0001"+
		"\u0000\u0000\u0000$\u0015\u0001\u0000\u0000\u0000$ \u0001\u0000\u0000"+
		"\u0000%\u0003\u0001\u0000\u0000\u0000&,\u0003\b\u0004\u0000\'+\u0003\n"+
		"\u0005\u0000(+\u0003\u0010\b\u0000)+\u0005\u0002\u0000\u0000*\'\u0001"+
		"\u0000\u0000\u0000*(\u0001\u0000\u0000\u0000*)\u0001\u0000\u0000\u0000"+
		"+.\u0001\u0000\u0000\u0000,*\u0001\u0000\u0000\u0000,-\u0001\u0000\u0000"+
		"\u0000-/\u0001\u0000\u0000\u0000.,\u0001\u0000\u0000\u0000/0\u0003\f\u0006"+
		"\u000001\u0006\u0002\uffff\uffff\u00001<\u0001\u0000\u0000\u000026\u0003"+
		"\n\u0005\u000036\u0003\u0010\b\u000046\u0005\u0002\u0000\u000052\u0001"+
		"\u0000\u0000\u000053\u0001\u0000\u0000\u000054\u0001\u0000\u0000\u0000"+
		"67\u0001\u0000\u0000\u000075\u0001\u0000\u0000\u000078\u0001\u0000\u0000"+
		"\u000089\u0001\u0000\u0000\u00009<\u0003\f\u0006\u0000:<\u0003\f\u0006"+
		"\u0000;&\u0001\u0000\u0000\u0000;5\u0001\u0000\u0000\u0000;:\u0001\u0000"+
		"\u0000\u0000<\u0005\u0001\u0000\u0000\u0000=?\u0005\u0005\u0000\u0000"+
		">=\u0001\u0000\u0000\u0000?B\u0001\u0000\u0000\u0000@>\u0001\u0000\u0000"+
		"\u0000@A\u0001\u0000\u0000\u0000AD\u0001\u0000\u0000\u0000B@\u0001\u0000"+
		"\u0000\u0000CE\u0005\b\u0000\u0000DC\u0001\u0000\u0000\u0000EF\u0001\u0000"+
		"\u0000\u0000FD\u0001\u0000\u0000\u0000FG\u0001\u0000\u0000\u0000GI\u0001"+
		"\u0000\u0000\u0000HJ\u0005\u0004\u0000\u0000IH\u0001\u0000\u0000\u0000"+
		"IJ\u0001\u0000\u0000\u0000JP\u0001\u0000\u0000\u0000KP\u0005\u0002\u0000"+
		"\u0000LM\u0005\u0001\u0000\u0000MP\u0005\n\u0000\u0000NP\u0005\u0001\u0000"+
		"\u0000O@\u0001\u0000\u0000\u0000OK\u0001\u0000\u0000\u0000OL\u0001\u0000"+
		"\u0000\u0000ON\u0001\u0000\u0000\u0000P\u0007\u0001\u0000\u0000\u0000"+
		"QS\u0005\u0005\u0000\u0000RQ\u0001\u0000\u0000\u0000SV\u0001\u0000\u0000"+
		"\u0000TR\u0001\u0000\u0000\u0000TU\u0001\u0000\u0000\u0000UW\u0001\u0000"+
		"\u0000\u0000VT\u0001\u0000\u0000\u0000WX\u0005\u0001\u0000\u0000Xb\u0006"+
		"\u0004\uffff\uffff\u0000Y[\u0005\u0005\u0000\u0000ZY\u0001\u0000\u0000"+
		"\u0000[^\u0001\u0000\u0000\u0000\\Z\u0001\u0000\u0000\u0000\\]\u0001\u0000"+
		"\u0000\u0000]_\u0001\u0000\u0000\u0000^\\\u0001\u0000\u0000\u0000_`\u0005"+
		"\b\u0000\u0000`b\u0006\u0004\uffff\uffff\u0000aT\u0001\u0000\u0000\u0000"+
		"a\\\u0001\u0000\u0000\u0000b\t\u0001\u0000\u0000\u0000cg\u0003\u000e\u0007"+
		"\u0000dg\u0005\t\u0000\u0000eg\u0005\n\u0000\u0000fc\u0001\u0000\u0000"+
		"\u0000fd\u0001\u0000\u0000\u0000fe\u0001\u0000\u0000\u0000g\u000b\u0001"+
		"\u0000\u0000\u0000hi\u0005\u0007\u0000\u0000ij\u0006\u0006\uffff\uffff"+
		"\u0000j\r\u0001\u0000\u0000\u0000km\u0005\u0005\u0000\u0000lk\u0001\u0000"+
		"\u0000\u0000mp\u0001\u0000\u0000\u0000nl\u0001\u0000\u0000\u0000no\u0001"+
		"\u0000\u0000\u0000or\u0001\u0000\u0000\u0000pn\u0001\u0000\u0000\u0000"+
		"qs\u0005\b\u0000\u0000rq\u0001\u0000\u0000\u0000st\u0001\u0000\u0000\u0000"+
		"tr\u0001\u0000\u0000\u0000tu\u0001\u0000\u0000\u0000uw\u0001\u0000\u0000"+
		"\u0000vx\u0005\u0004\u0000\u0000wv\u0001\u0000\u0000\u0000wx\u0001\u0000"+
		"\u0000\u0000x\u000f\u0001\u0000\u0000\u0000yz\u0005\u0006\u0000\u0000"+
		"z\u0011\u0001\u0000\u0000\u0000\u0014\u001a\u001e\"$*,57;@FIOT\\afntw";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}