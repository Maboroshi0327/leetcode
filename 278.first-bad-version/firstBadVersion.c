// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int first = 1;
    int last = n;

    while (first < last) {
        int middle = first + (last - first) / 2;
        bool middleBad = isBadVersion(middle);

        if (middleBad)
            last = middle;
        else
            first = middle + 1;
    }

    return first;
}
