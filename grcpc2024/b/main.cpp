#include <bits/stdc++.h>

using namespace std;

class Person {
public:
  long long id;
  long long element;

  Person(long long i, long long e) {
    id = i;
    element = e;
  }
};

long long m;
bool comp(Person a, Person b) {
  long long ta = (a.element + m - 1) / m;
  long long tb = (b.element + m - 1) / m;
  if (ta == tb)
    return a.id < b.id;
  return ta < tb;
}
int main() {
  long long n;
  scanf("%lld %lld", &n, &m);
  vector<Person> list;
  for (int i = 0; i < n; i++) {
    long long a;
    scanf("%lld", &a);
    list.push_back(Person(i, a));
  }
  sort(list.begin(), list.end(), comp);
  for (int i = 0; i < list.size(); i++) {
    printf("%lld ", list[i].id + 1);
  }
  printf("\n");
}
