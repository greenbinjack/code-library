#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n, x1, y1, z1, x2, y2, z2, x_common_part, y_common_part, z_common_part, xMax, yMax, zMax, xMin, yMin, zMin;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> n;
        xMax = yMax = zMax = 0;
        xMin = yMin = zMin = INT_MAX;
        for(int j=1;j<=n;j++)
        {
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            xMax = max(xMax, x1);
            yMax = max(yMax, y1);
            zMax = max(zMax, z1);
            xMin = min(xMin, x2);
            yMin = min(yMin, y2);
            zMin = min(zMin, z2);
        }
        x_common_part = xMin - xMax;
        y_common_part = yMin - yMax;
        z_common_part = zMin - zMax;
        cout << "Case " << i << ": ";
        if(x_common_part > 0 && y_common_part > 0 && z_common_part > 0) cout << x_common_part * y_common_part * z_common_part << endl;
        else cout << 0 << endl;
    }
    return 0;
}

