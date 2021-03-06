#define MAXN 5007

const LD EPS = 1e-6;
int n;
int zmienna[MAXN];
LD m[MAXN][MAXN],wyn[MAXN];

bool IsZero(LD x) {
  return x >= -EPS && x <= EPS;
}

int szukaj(int w, int k) {
  FOR(i,w,n-1) if (!IsZero(m[i][k])) return i;
  return -1;
}

int Gauss() {
  int w = 0, k = 0, res = 0;
  while (k < n) {
    int p = szukaj(w,k);
    if (p == -1) res = 1,zmienna[w] = -1;
    else {
      swap(m[p],m[w]);
      zmienna[w] = k;
      FOR(i,w+1,n-1) {
        LD stos = m[i][k]/m[w][k];
        FOR(j,k,n) m[i][j] -= stos*m[w][j];
      } 
      ++w; 
    }
    ++k;
  }
  FOR(i,w,n-1) if (!IsZero(m[i][n])) return -1;
  FORD(i,w-1,0) {
    int x = zmienna[i];
    wyn[x] = m[i][n];
    FOR(j,x+1,n-1) wyn[x] -= wyn[j]*m[i][j];
    wyn[x] /= m[i][x]; 
  }
  return res;
}  

int main(){
  scanf("%d",&n);
  REP(i,n) REP(j,n+1) scanf("%Lf",&m[i][j]);
  //-1 sprzeczny, 0 jednoznaczny, 1 niejednoznaczny
  int res = Gauss();
  printf("%d\n",res);
  if (res != -1) {REP(i,n) printf("x%d = %Lf\n",i+1,wyn[i]);}
  return 0;
}
