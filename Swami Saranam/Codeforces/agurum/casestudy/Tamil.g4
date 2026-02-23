grammar Tamil;

@header {
    import java.util.*;
}

@members {
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
}

file
    : sentence EOF
    ;

sentence
    : clause (LINK_WORD clause)* (PUNCT | QUESTION_MARK)?
    | validVerbless (PUNCT | QUESTION_MARK)?
    ;

// 1. STANDARD CLAUSES: A verbPhrase is REQUIRED structurally here.
clause
    : subject (object | adverb | QUESTION_WORD)* verbPhrase
      { checkAgreement($subject.textVal, $verbPhrase.verbVal, $ctx.getText()); }
    | (object | adverb | QUESTION_WORD)+ verbPhrase
    | verbPhrase
    ;

// 2. EXPLICITLY ALLOWED VERBLESS PHRASES: These bypass the verb requirement.
validVerbless
    : ADJ* TAMIL_WORD+ POSTPOSITION?   // Example: "அழகான மலர்", "நல்ல மாணவன்"
    | QUESTION_WORD                    // Example: "எப்படி"
    | PRONOUN NUMBER                   // Example: "நான் 25"
    | PRONOUN                          // Example: "அவன்"
    ;

subject returns [String textVal]
    : ADJ* PRONOUN { $textVal = $PRONOUN.getText(); }
    | ADJ* TAMIL_WORD { $textVal = $TAMIL_WORD.getText(); }
    ;

object
    : nounPhrase
    | TAMIL_NUMBER
    | NUMBER
    ;

verbPhrase returns [String verbVal]
    : ts=ACTION_VERB { $verbVal = $ts.getText(); }
    ;

nounPhrase
    : ADJ* TAMIL_WORD+ POSTPOSITION?
    ;

adverb
    : ADV
    ;

/* LEXER RULES */
PRONOUN : 'நான்' | 'நாங்கள்' | 'அவன்' | 'அவள்' | 'அவர்கள்' ;
QUESTION_WORD : 'எது' | 'எங்கே' | 'எப்படி' | 'ஏன்' | 'எப்போது' | 'என்ன' ;
LINK_WORD : 'ஆனால்' | 'ஆகவே' | 'எனவே' | 'அதனால்' | 'பின்' ;
POSTPOSITION : 'உள்ளே' | 'மேலே' | 'கீழே' | 'இல்' | 'உடன்' ;
ADJ : 'அழகான' | 'புதிய' | 'பழைய' | 'நல்ல' | 'நான்கு' ;
ADV : 'வேகமாக' | 'மெல்ல' | 'மெதுவாக' ;

ACTION_VERB
    : 'வந்தான்' | 'வந்தாள்' | 'வந்தார்கள்' | 'வந்தேன்' | 'வந்தோம்' | 'வந்தார்' | 'வந்தாய்'
    | 'படித்தான்' | 'படித்தாள்' | 'படித்தார்கள்' | 'படித்தோம்'
    | 'ஓடினான்' | 'ஓடினார்கள்'
    | 'உள்ளான்' | 'உள்ளது' | 'உள்ளுது' | 'உள்ளார்' | 'உள்ள'
    | 'சாப்பிட்டேன்'
    | 'வாங்கினான்' | 'வாங்கினேன்' | 'வாங்கினார்கள்'
    | 'சென்றான்' | 'சென்றாள்' | 'சென்றார்கள்' | 'சென்றோம்' | 'செல்கிறோம்'
    | 'நடந்தான்' | 'நடந்தாள்' | 'நடந்தோம்'
    | 'வரவில்லை' | 'வேண்டும்' | 'தொடங்கும்' | 'கண்டனர்'
    | 'பாடினாள்' | 'பாடினார்கள்'
    | 'மலர்ந்தது'
    | 'இருந்தார்கள்' | 'இருந்தார்'
    | 'ஏறினான்'
    | 'விழுந்தான்'
    | 'மகிழ்ந்தாள்'
    | 'கட்டினார்கள்' | 'கட்டினோம்'
    | 'மறுத்தான்'
    ;

TAMIL_WORD : (TAMIL_CLUSTER)+ ;
fragment TAMIL_CLUSTER : TAMIL_BASE TAMIL_MARK* ;
fragment TAMIL_BASE : [\u0B85-\u0BB9] ;
fragment TAMIL_MARK : [\u0BBE-\u0BCD\u0BD7] ;
TAMIL_NUMBER : [\u0BE6-\u0BEF]+ ;
NUMBER : [0-9]+ ;
QUESTION_MARK : '?' ;
PUNCT : [!.,;:] ;
WS : [ \t\r\n]+ -> skip ;
ERROR_CHAR : . ;