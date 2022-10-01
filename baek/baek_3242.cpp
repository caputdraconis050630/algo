#include "bits/stdc++.h"
using namespace std;

class naredba { public: int bio, p1, p2; };
vector< naredba > program;

void input() {
   int t;
   string s;
   naredba x;

   x.bio = 1; x.p1 = x.p2 = 0;
   for( ;; ) {
      cin >> s;
      if( s != "ILI" ) {
         program.push_back( x );
         x.bio = 0; x.p1 = x.p2 = 0;
      }
      if( s == "." ) break;
      if( s == "RADI" ) x.p1 = program.size()+1;
      if( s == "IDI" ) cin >> x.p1;
      if( s == "ILI" ) cin >> x.p2;
   }
   x.bio = 1; x.p1 = x.p2 = 0;
   program.push_back( x );
}

void dfs( int i ) {
   if( program[i].bio ) return;
   program[i].bio = 1;
   dfs( program[i].p1 );
   dfs( program[i].p2 );
}

void output() {
   int i, rez = 0;
   for( i = 0; i < program.size()-1; ++i )
      if( !program[i].bio ) rez++;
   cout << rez << endl;
}

int main( void ) {
   input();
   dfs( 1 );
   output();
   return 0;
}
