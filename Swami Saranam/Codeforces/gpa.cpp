#include <iostream>
using namespace std;

double convert(double score, double out_of, double converted_to) {
    return (score / out_of) * converted_to;
}

int main() {
    cout << "=== Marks Calculator (Hardcoded + Input for Pending) ===\n";

    // --- Computer Networks ---
    double cn_midsem = convert(20, 50, 20);  // hardcoded
    double cn_lab1   = convert(9, 10, 10);   // hardcoded 
    double cn_quiz   = convert(10, 10, 5);   // hardcoded

    double cn_quiz2, cn_lab2, cn_case;
    cout << "\n--- Computer Networks (Pending Marks) ---\n";
    cout << "Quiz 2 (out of 20): "; cin >> cn_quiz2;
    cout << "Lab Eval 2 (out of 25): "; cin >> cn_lab2;
    cout << "Case Study (out of 50): "; cin >> cn_case;

    double cn_total = cn_midsem + cn_lab1 + cn_quiz 
                    + convert(cn_quiz2, 20, 5) 
                    + convert(cn_lab2, 25, 15) 
                    + convert(cn_case, 50, 15);

    cout << "Computer Networks Total = " << cn_total << "/70\n";


    // --- TOC ---
    double toc_midsem = convert(20, 50, 20); // hardcoded
    double toc_quiz1  = convert(9, 10, 10);  // hardcoded
    double toc_quiz2  = convert(10, 10, 10); // hardcoded

    double toc_quiz3;
    cout << "\n--- TOC (Pending Marks) ---\n";
    cout << "Quiz 3 (out of 10): "; cin >> toc_quiz3;

    double toc_total = toc_midsem + toc_quiz1 + toc_quiz2 
                     + convert(toc_quiz3, 10, 10);

    cout << "TOC Total = " << toc_total << "/50\n";


    // --- Machine Learning ---
    double ml_midsem = convert(21, 50, 20);  // hardcoded
    double ml_lab1   = convert(35, 40, 10);  // hardcoded
    double ml_quiz1  = convert(20, 20, 5);   // hardcoded

    double ml_quiz2, ml_lab2, ml_lab3;
    cout << "\n--- Machine Learning (Pending Marks) ---\n";
    cout << "Quiz 2 (out of 20): "; cin >> ml_quiz2;
    cout << "Lab Eval 2 (out of 40): "; cin >> ml_lab2;
    cout << "Lab Eval 3 (out of 40): "; cin >> ml_lab3;

    double ml_total = ml_midsem + ml_lab1 + ml_quiz1
                    + convert(ml_quiz2, 20, 5)
                    + convert(ml_lab2, 40, 15)
                    + convert(ml_lab3, 40, 15);

    cout << "Machine Learning Total = " << ml_total << "/70\n";


    // --- NLP ---
    double nlp_quiz1 = convert(8, 10, 5); // hardcoded

    double nlp_midsem, nlp_quiz2, nlp_lab1, nlp_lab2, nlp_case;
    cout << "\n--- NLP (Pending Marks) ---\n";
    cout << "Midsem (out of 50): "; cin >> nlp_midsem;
    cout << "Quiz 2 (out of 10): "; cin >> nlp_quiz2;
    cout << "Lab Eval 1 (out of 25): "; cin >> nlp_lab1;
    cout << "Lab Eval 2 (out of 25): "; cin >> nlp_lab2;
    cout << "Case Study (out of 50): "; cin >> nlp_case;

    double nlp_total = nlp_quiz1
                     + convert(nlp_midsem, 50, 20)
                     + convert(nlp_quiz2, 10, 5)
                     + convert(nlp_lab1, 25, 15)
                     + convert(nlp_lab2, 25, 10)
                     + convert(nlp_case, 50, 15);

    cout << "NLP Total = " << nlp_total << "/70\n";


    // --- Embedded Systems (all pending, so ask) ---
    double emb_midsem, emb_quiz1, emb_quiz2, emb_lab1, emb_lab2, emb_case;
    cout << "\n--- Embedded Systems (Pending Marks) ---\n";
    cout << "Midsem (out of 50): "; cin >> emb_midsem;
    cout << "Quiz 1 (out of 20): "; cin >> emb_quiz1;
    cout << "Quiz 2 (out of 20): "; cin >> emb_quiz2;
    cout << "Lab Eval 1 (out of 25): "; cin >> emb_lab1;
    cout << "Lab Eval 2 (out of 25): "; cin >> emb_lab2;
    cout << "Case Study (out of 50): "; cin >> emb_case;

    double emb_total = convert(emb_midsem, 50, 20)
                     + convert(emb_quiz1, 20, 5)
                     + convert(emb_quiz2, 20, 5)
                     + convert(emb_lab1, 25, 10)
                     + convert(emb_lab2, 25, 15)
                     + convert(emb_case, 50, 15);

    cout << "Embedded Systems Total = " << emb_total << "/70\n";


    // --- Grand Total ---
    double grand_total = cn_total + toc_total + ml_total + nlp_total + emb_total;
    cout << "\n=== Grand Total ===\n";
    cout << "Grand Total = " << grand_total << " / 330\n";

    return 0;
}
