#include <iostream>
#include <vector>
#include <string>
using namespace std;

double convert(double score, double out_of, double converted_to) {
    return (score / out_of) * converted_to;
}

struct Component {
    double score;
    double out_of;
    double to;
};

void computeSubject(string name,
                    double midsem, double midsem_out, double midsem_to,
                    vector<Component> quizzes,
                    vector<Component> labs,
                    Component case_study,
                    double endsem_out, double endsem_to,
                    bool isTOC=false) 
{
    double total = 0;

    cout << "\n--- " << name << " ---\n";

    // Midsem
    if (midsem >= 0) {
        double midsem_conv = convert(midsem, midsem_out, midsem_to);
        total += midsem_conv;
        cout << "Midsem: " << midsem << " / " << midsem_out
             << " → " << midsem_conv << " / " << midsem_to << endl;
    }

    // Quizzes
    double quiz_total = 0, quiz_max = 0;
    for (auto &q : quizzes) {
        double val = convert(q.score, q.out_of, q.to);
        cout << "Quiz: " << q.score << " / " << q.out_of
             << " → " << val << " / " << q.to << endl;
        quiz_total += val;
        quiz_max += q.to;
    }
    total += quiz_total;

    // Labs
    double lab_total = 0, lab_max = 0;
    for (auto &l : labs) {
        double val = convert(l.score, l.out_of, l.to);
        cout << "Lab: " << l.score << " / " << l.out_of
             << " → " << val << " / " << l.to << endl;
        lab_total += val;
        lab_max += l.to;
    }
    total += lab_total;

    // Case Study
    if (case_study.to > 0) {
        double cs_conv = convert(case_study.score, case_study.out_of, case_study.to);
        total += cs_conv;
        cout << "Case Study: " << case_study.score << " / " << case_study.out_of
             << " → " << cs_conv << " / " << case_study.to << endl;
    }

    // Total before Endsem
    int base_total = isTOC ? 50 : 70;
    cout << "Total (without Endsem): " << total << " / " << base_total << endl;

    // Requirement for 85
    double needed = max(0.0, 85.0 - total);
    if (needed > endsem_to) {
        cout << "❌ Even full endsem won't reach 85.\n";
    } else {
        double required_raw = (needed / endsem_to) * endsem_out;
        cout << "Need " << needed << " more → " << required_raw
             << " / " << endsem_out << " in endsem.\n";
    }
}

int main() {
    // Embedded Systems
    computeSubject("Embedded Systems",
                   26, 50, 20,
                   {{5,10,5}, {20,20,5}},
                   {{23,25,10}, {25,25,15}},
                   {50,50,15},
                   50, 30);

    // Computer Networks
    computeSubject("Computer Networks",
                   22, 50, 20,
                   {{38,40,10}, {10,10,10}},
                   {{9,10,10}, {9,10,10}},
                   {50,50,10},
                   50, 30);

    // Theory of Computation (TOC uses /50 total instead of /70)
    computeSubject("Theory of Computation",
                   19, 50, 20,
                   {{9,10,5}, {10,10,5}, {6,10,5}},
                   {},
                   {14,15,15},
                   100, 50, true);

    // Machine Learning
    computeSubject("Machine Learning",
                   21, 50, 20,
                   {{20,20,5}, {20,20,5}},
                   {{35,40,10}, {30,30,15}, {28,30,15}},
                   {0,0,0},
                   50, 30);

    // NLP
    computeSubject("Natural Language Processing",
                   24, 50, 20,
                   {{8,10,5}, {10,10,5}},
                   {{15,15,15}, {10,10,10}},
                   {15,15,15},
                   50, 30);

    // Quantum Computing
    computeSubject("Quantum Computing",
                   40, 50, 20,
                   {{10,10,5}, {10,10,5}},
                   {{15,15,15}, {10,10,10}},
                   {15,15,15},
                   50, 30);

    return 0;
}
