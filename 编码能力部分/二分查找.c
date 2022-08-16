//
// Created by XuanLang Z on 2021/2/16.
//

int binary_search(int *arr, int n, int x) {
    int l = 0, r = n - 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) r = mid - 1; else l = mid + 1;
    }
    return -1;
}