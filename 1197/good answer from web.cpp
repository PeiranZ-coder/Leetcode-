class Solution {
public:
    int minKnightMoves(int x, int y) {
        x=abs(x);
        y=abs(y);
        if (x<y) swap(x,y);
        if (x==1 && y==0) return 3;
        if (x==2 && y==2) return 4;
        int ans=max((x+1)/2,(x+y+2)/3);
        return (ans+x+y)&1 ? ans+1:ans;
    }
};
