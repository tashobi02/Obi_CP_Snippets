#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define enl "\n"

// Default random number generator
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void bernoulli_dist() {
    lli n;
    cin >> n;
    bernoulli_distribution dist(0.5); // p = 0.5 (fair coin toss)
    for (lli i = 0; i < n; i++) {
        cout << dist(rng) << " ";
    }
    cout << enl;
}

void geometric_dist() {
    lli n;
    cin >> n;
    geometric_distribution<lli> dist(0.5); // p = 0.5
    for (lli i = 0; i < n; i++) {
        cout << dist(rng) << " ";
    }
    cout << enl;
}

void binomial_dist() {
    lli n;
    cin >> n;
    binomial_distribution<lli> dist(10, 0.5); // n = 10 trials, p = 0.5
    for (lli i = 0; i < n; i++) {
        cout << dist(rng) << " ";
    }
    cout << enl;
}

void pascal_dist() {
    lli n;
    cin >> n;
    lli r = 5;      // Number of successes
    double p = 0.3; // Success probability
    binomial_distribution<lli> binom_dist(1, p);
    for (lli i = 0; i < n; i++) {
        lli trials = 0, successes = 0;
        while (successes < r) {
            trials++;
            if (binom_dist(rng) == 1)
                successes++;
        }
        cout << trials << " ";
    }
    cout << enl;
}

void poisson_dist() {
    lli n;
    cin >> n;
    poisson_distribution<lli> dist(3.0); // lambda = 3
    for (lli i = 0; i < n; i++) {
        cout << dist(rng) << " ";
    }
    cout << enl;
}

void uniform_dist() {
    lli n;
    cin >> n;
    uniform_int_distribution<lli> dist(0, 100); // Random integers between 0 and 100
    for (lli i = 0; i < n; i++) {
        cout << dist(rng) << " ";
    }
    cout << enl;
}

void exponential_dist() {
    lli n;
    cin >> n;
    exponential_distribution<double> dist(1.0); // lambda = 1.0
    for (lli i = 0; i < n; i++) {
        cout << dist(rng) << " ";
    }
    cout << enl;
}

void gamma_dist() {
    lli n;
    cin >> n;
    gamma_distribution<double> dist(2.0, 2.0); // alpha = 2, beta = 2
    for (lli i = 0; i < n; i++) {
        cout << dist(rng) << " ";
    }
    cout << enl;
}

void normal_dist() {
    lli n;
    cin >> n;
    normal_distribution<double> dist(50.0, 15.0); // mean = 50, sigma = 15
    for (lli i = 0; i < n; i++) {
        cout << dist(rng) << " ";
    }
    cout << enl;
}

void lognormal_dist() {
    lli n;
    cin >> n;
    lognormal_distribution<double> dist(0.0, 1.0); // mean = 0, stddev = 1
    for (lli i = 0; i < n; i++) {
        cout << dist(rng) << " ";
    }
    cout << enl;
}

int main() {
    lli t = 1; // Number of iterations
    while (t--) {
        // Call each distribution function as needed
        bernoulli_dist();
        geometric_dist();
        binomial_dist();
        pascal_dist();
        poisson_dist();
        uniform_dist();
        exponential_dist();
        gamma_dist();
        normal_dist();
        lognormal_dist();
    }
    return 0;
}
// AI Generated - will be edited later