#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

#define pb push_back

typedef vector<int> vi;

/*
 * 考え方
 * まず上司と部下の関係を作る
 * 部下を持たない場合は給料は1と決められる
 * あとは社員番号が小さほど偉くなるので、社員番号の降順で部下から上司というふうに給料を決めていく
 * 部下が1人しかいないときはmaxとminが一致するので部下が複数いるときと区別する必要はない
*/
int main(void) {
    int n;
    cin >> n;

    map<int, vi> boss_id_to_sub_ids;
    vi salary(n + 1, 0);

    for (int i = 0; i < n - 1; ++i) {
        int boss;
        cin >> boss;
        boss_id_to_sub_ids[boss].pb(i + 2);
    }

    for (int id = n; id >= 1; --id) {
        if (boss_id_to_sub_ids.count(id) == 0) {
            salary[id] = 1;
        } else {
            int _max = -1;
            int _min = 1 << 30;
            for (auto sub_id: boss_id_to_sub_ids[id]) {
                if (salary[sub_id] > _max) _max = salary[sub_id];
                if (salary[sub_id] < _min) _min = salary[sub_id];
            }
            salary[id] = _max + _min + 1;
        }
    }

    cout << salary[1] << endl;
}
