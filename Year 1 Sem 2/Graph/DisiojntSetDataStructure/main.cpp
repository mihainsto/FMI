#include <iostream>
#include <fstream>
#include <map>
using namespace std;
int fatherOf[100002];
int grade[100002];
int findFather(int node){
    if(fatherOf[node] == node){
        return node;
    }
    fatherOf[node] = findFather(fatherOf[node]);
    return fatherOf[node];
}
int Disjoint(int o, int x, int y)
{
    int A,B;
    A = findFather(x); B = findFather(y);
    if(o==2 && A==B && A != 0) return true;
    else if(o==2) return false;
    if(A == B) return false;
    if(grade[A] < grade[B]){
        fatherOf[A] = B;
        grade[B] += grade[A];
    } else{
        fatherOf[B] = A;
        grade[A] += grade[B];
    }
    return false;
}
int main() {
    int n,m,x,y,A,B,o;
    ifstream f("disjoint.in");
    ofstream g("disjoint.out");
    f>>n>>m;
    for(int i=1;i<=n;i++){
        fatherOf[i] = i;
        grade[i] = 1;
    }
    for(int i=1;i<=m;i++){
        f>>o;
        f>>x>>y;
        int r = Disjoint(o, x, y);
        if(o == 2){
            if(r == false) g<<"NU\n";
            else g<<"DA\n";
        }
        
     }
    return 0;
}
