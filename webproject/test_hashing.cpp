// unordered_set::begin/end example
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class ThreeD {
public:
    int ht;
    int wid;
    int dep;
    ThreeD(int i, int j, int k) : ht(2 * i), wid(2 * j), dep(2 * k) {}
    ThreeD() {}
    int vol() const { return ht * wid * dep; }
    int surface() const { return 2 * (ht * wid + wid * dep + dep * ht); }
    bool operator==(const ThreeD& t) const { return vol() == t.vol(); }
    // bool operator<(const ThreeD& t) const { return vol() < t.vol(); }
};
class myCompareClass2 {

public:
    bool operator()(const int& t1, const int& t2) const { return t1 % 10 == t2 % 10; }
    size_t operator()(const int& t) const { return hash<int>()(t * t + 31); }
    size_t operator()(const ThreeD& t) const { return hash<int>()(t.vol() + t.surface()); }
    bool operator()(const ThreeD& t1, const ThreeD& t2) const { return t1.surface() == t2.surface(); }
};

class myCompareClass {
public:
    size_t operator()(int i) const {
        std::hash<int> h;
        return h((i * i - 24) % 17);

    }

};

class myCompareClass1 {
public:
    size_t operator()(int i) const {
        std::hash<int> h;
        return h(i);
        //return std::hash<int>()(i); replace the two statements above

    }

};

int main()
{

    std::unordered_set<int, myCompareClass1> set30 = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 };
    for (auto i : set30) { std::cout << i << " "; }
    std::cout << std::endl;
    for (unsigned i = 0; i < set30.bucket_count(); ++i) {
        std::cout << "bucket #" << i << " contains:";
        for (auto local_it = set30.begin(i); local_it != set30.end(i); ++local_it)
            std::cout << " " << *local_it;
        std::cout << std::endl;
    }


    std::unordered_set<int, myCompareClass> set3 = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 };
    for (auto i : set3) { std::cout << i << " "; }
    std::cout << std::endl;
    std::unordered_set<int> set4 = { 1111,2,3,4,5555,6,7,8,9,10000,11,12,13,14444,15,16,17,1866,19,20,2111,22,23,24444,25,26,27,28888,29,30 };
    for (auto i : set4) { std::cout << i << " "; }//The printing order is quite unpredictable; this is not important for Hash Table

    std::cout << std::endl;


    std::unordered_set<std::string> myset1{ "AA", "BB", "CC", "DD", "EE", "FF", "GG", "HH", "II" };
    for (auto i : myset1) { std::cout << i << " "; }//Again, the printing order is unpredictable
    std::cout << std::endl;
    std::unordered_set<std::string> myset =
    { "Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune" };


    std::cout << "myset contains:";
    for (auto it = myset.begin(); it != myset.end(); ++it)
        std::cout << " " << *it;
    std::cout << std::endl;
    std::cout << "myset's buckets contain:\n";
    for (unsigned i = 0; i < myset.bucket_count(); ++i) {
        std::cout << "bucket #" << i << " contains:";
        for (auto local_it = myset.begin(i); local_it != myset.end(i); ++local_it)
            std::cout << " " << *local_it;
        std::cout << std::endl;
    }
    auto it = myset.find("Venus");//constant time operation O(1).
    std::cout << *it << std::endl;

    unordered_map<int, string> H2{ {1, "Dave"}, {2, "Mary"}, {3, "Vijay"}, {4, "Bob"}, {5, "Sanjay"}, {6, "Nancy"}, {7, "John"},
        {8, "Tammy"}, {9, "Jim"}, {10, "Mike"} };
    for (auto i : H2) { cout << i.first << " " << i.second << "   "; }
    cout << endl;

    cout << H2[7] << endl;//constant time operation O(1).


    std::cout << std::endl;
    std::cout << "H2's buckets contain:\n";
    for (unsigned i = 0; i < H2.bucket_count(); ++i) {
        std::cout << "bucket #" << i << " contains:" << H2.bucket_size(i) << " elements :";
        for (auto local_it = H2.begin(i); local_it != H2.end(i); ++local_it)
            std::cout << " " << local_it->first << " " << local_it->second << "   " << endl;
        std::cout << std::endl;
    }
    cout << endl;
    for (auto i : H2) {
        cout << "{" << i.first << " " << i.second << "} is in bucket #" << H2.bucket(i.first) << endl;
    }
    H2.insert({ 3,"Gary" });//will be ignored
    cout << H2[3] << endl;
    H2[3] = "Gary";//Will override
    cout << H2[3] << endl;
    H2.insert({ 11, "Jeff" });
    H2.erase(4);
    cout << H2.size();

    ThreeD  t1(1, 1, 1), t2(2, 2, 2), t3(3, 3, 3), t4(4, 4, 4), t5(5, 5, 5), t6(6, 6, 6), t7(7, 7, 7), t8(8, 8, 8), t9(9, 9, 9), t10(10, 10, 10);
    unordered_map<int, ThreeD, myCompareClass2> H3{ {1, t1}, {2, t2}, {3, t3}, {4, t4}, {5, t5}, {6, t6}, {7, t7}, {8, t8},{9,t9},{10, t10} };

    unordered_map<int, ThreeD, myCompareClass2, myCompareClass2> H4{ {1, t1}, {2, t2}, {3, t3}, {4, t4}, {5, t5}, {6, t6}, {7, t7}, {8, t8},{9,t9},{10, t10} };
    unordered_map<ThreeD, int, myCompareClass2> H5{ {t1,1}, {t2,2}, {t3, 3}, {t4, 4}, {t5, 5}, {t6, 6}, {t7, 7}, {t8, 8},{t9,9},{t10, 10} };
    unordered_map<ThreeD, int, myCompareClass2, myCompareClass2> H6{ {t1,1}, {t2,2}, {t3, 3}, {t4, 4}, {t5, 5}, {t6, 6}, {t7, 7}, {t8, 8},{t9,9},{t10, 10} };
    return 0;
}
