#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
vector<int> v_score;

class Person {
   private:
    int full_score;
    int recent_score;

   public:
    Person() {
        full_score = 0;
        recent_score = 0;
    }

    void add_score() {
        int score;
        cin >> score;

        full_score += score;
        recent_score = score;

        v_score.push_back(score);
    }

    int get_score() { return full_score; }
    int get_recent_score() { return recent_score; }
};

void print_rank() {
    int size = v_score.size();
    vector<int> sorted_score(size);
    copy(v_score.begin(), v_score.end(), sorted_score.begin());
    sort(sorted_score.begin(), sorted_score.end(), greater<int>());

    for (int i = 0; i < size; i++) {
        if (i != 0) cout << " ";
        int rank = 1 +
                   find(sorted_score.begin(), sorted_score.end(), v_score[i]) -
                   sorted_score.begin();
        cout << rank;
    }
    cout << endl;

    v_score.clear();
    vector<int>().swap(v_score);
}

int main(int argc, char** argv) {
    int N;
    int score;
    cin >> N;
    Person* p = new Person[N];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            p[j].add_score();
        }
        print_rank();
    }

    for (int j = 0; j < N; j++) {
        v_score.push_back(p[j].get_score());
    }
    print_rank();

    delete[] p;

    return 0;
}