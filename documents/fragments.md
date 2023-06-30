# 动态规划

## 背包问题

### 核心状态转移方程

$$f_j = max(f_j, f[j - w[i]] + v[i])$$

### 几种背包问题核心代码

#### 01背包

``` c++
for(int i = 1; i <= n; ++ i){
    cin >> w[i] >> v[i];
    for(int j = m; j >= w[i]; -- j)
        f[j] = max(f[j], f[j - w[i]] + v[i]);
}
cout << f[m] << endl;
```

#### 完全背包

``` c++
for(int i = 1; i <= n; ++ i){
    cin >> w[i] >> v[i];
    for(int j = w[i]; j <= m; ++ j)
        f[j] = max(f[j], f[j - w[i]] + v[i]);
}
cout << f[m] << endl;
```

#### 多重背包

##### 纯净版本

``` c++
cin >> n >> W;
for (int i = 1; i <= n; ++ i) {
    cin >> v[i] >> w[i] >> m[i];
    for (int j = W; j >= w[i]; -- j)
        for (int k = 1; k <= m[i] && k * w[i] <= j; ++ k)
            f[j] = max(f[j], f[j - k * w[i]] + k * v[i]);
}
cout << f[W] << endl;
```

##### 带二进制分组优化

```c++
cin >> n >> m;

int vi, wi, mi;
for (int i = 1; i <= n; ++ i) {
    cin >> vi >> wi >> mi;
    for (int j = 1; j <= mi; j <<= 1)
        v[++ cnt] = j * vi, w[cnt] = j * wi, mi -= j;
    if (mi) v[++ cnt] = vi * mi, w[cnt] = wi * mi;
}

for (int i = 1; i <= cnt; ++ i)
    for (int j = m; j >= w[i]; -- j)
        f[j] = max(f[j], f[j - w[i]] + v[i]);

cout << f[m] << endl;
```



