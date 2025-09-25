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
                    double endsem_out, double endsem_to) {
    double total = 0;

    // midsem
    if (midsem >= 0)
        total += convert(midsem, midsem_out, midsem_to);

    // quizzes
    for (auto &q : quizzes)
        total += convert(q.score, q.out_of, q.to);

    // labs
    for (auto &l : labs)
        total += convert(l.score, l.out_of, l.to);

    // case study
    if (case_study.to > 0)
        total += convert(case_study.score, case_study.out_of, case_study.to);

    double current = total;
    double needed = max(0.0, 85.0 - current);

    cout << "\n--- " << name << " ---\n";
    cout << "Current = " << current << " / " << (100 - endsem_to) << endl;

    if (needed > endsem_to) {
        cout<<current+endsem_to<<endl;
        cout << "❌ Not possible, even full endsem won't reach 85.\n";
    } else {
        double required_raw = (needed / endsem_to) * endsem_out;
        cout << "Need at least " << needed << " more → "<< required_raw << "/" << endsem_out << " in endsem.\n";
    }
}

int main() {
    // Embedded
    computeSubject("Embedded Systems",19, 50, 20, // midsem pending
                   {{5,10,5}, {20,20,5}}, // quizzes full-1
                   {{23,25,10}, {23,25,15}}, // labs full-1
                   {48,50,15}, // case study full-2
                   50, 30); // endsem

    // CN
    computeSubject("Computer Networks",
                   22, 50, 20, // midsem received
                   {{38,40,10}}, // quizzes full-1
                   {{9,10,10}, {25,25,15}}, // labs (one given, one full-1)
                   {50,50,15}, // case study full-2
                   50, 30); // endsem

    // TOC
    computeSubject("TOC",
                   22, 50, 20, // midsem
                   {{9,10,5}, {10,10,5}, {6,10,5}}, // quizzes
                   {}, // no labs
                   {15,15,15}, // no case study
                   100, 50); // endsem

    // ML
    computeSubject("Machine Learning",
                   21, 50, 20, // midsem
                   {{20,20,5}, {19,20,5}}, // quizzes full-1
                   {{35,40,10}, {39,40,15}, {39,40,15}}, // labs
                   {0,0,0}, // no case study
                   50, 30); // endsem

    // NLP
    computeSubject("NLP",20, 50, 20, // midsem pending
                   {{8,10,5}, {10,10,5}}, // quizzes (given + full-1)
                   {{15,15,15}, {10,10,10}}, // labs full-1
                   {14,15,15}, // case study full-2
                   50, 30);
    // quantum
    computeSubject("qantum computing",40, 50, 20, // midsem pending
                   {{10,10,5}, {10,10,5}}, // quizzes (given + full-1)
                   {{15,15,15}, {10,10,10}}, // labs full-1
                   {13,15,15}, // case study full-2
                   50, 30);
                    // endsem

    return 0;
}

// dude calculate maximum marks i can get 