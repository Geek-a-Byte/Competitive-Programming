///////////////////////////// Order Statistics Tree code template ///////////////////////////////////////

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
// find_by_order(k) : iterator to the k'th element (0-indexed)
// order_of_key(k) : number of items strictly smaller than k


/////////////////////////////  GP Hash Table code template  ///////////////////////////////////////////

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct chash {
  const int RANDOM = (long long)(make_unique<char>().get())
      ^ chrono::high_resolution_clock::now()
            .time_since_epoch()
            .count();
  static unsigned long long hash_f(unsigned long long x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  static unsigned hash_combine(unsigned a, unsigned b) {
    return a * 31 + b;
  }
  int operator()(int x) const { return hash_f(x) ^ RANDOM; }
  int operator()(pair<int, int> x) const {
    return hash_combine(x.first, x.second) ^ RANDOM;
  }
};
// gp_hash_table<int, int, chash> mp;
// gp_hash_table<ll, int, chash> mp;
// gp_hash_table<pair<int, int>, int, chash> mp;



