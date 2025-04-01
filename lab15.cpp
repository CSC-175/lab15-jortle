#include <iostream>
using namespace std;

// Function prototypes
void getInfo(int &, int &);
double computeWays(int, int);
double factorial(int);

/*******************************************************************
 * getLotteryInfo                                                   *
 * Gets and validates lottery info from the user and places it in   *
 * reference parameters referencing variables in the main function. *
 ********************************************************************/

void getInfo(int &pickFrom, int &numPicks) {
  cout << "How many balls (1-12) are in the pool to pick from? ";
  cin >> pickFrom;
  if (pickFrom < 1 or pickFrom > 12) {
    cout << "Input Error! There must be between 1 and 12 balls." << endl;
    cout << "How many balls (1-12) are in the pool to pick from? ";
    cin >> pickFrom;
  }
  cout << "How many balls (1-" << pickFrom << ") will be drawn?";
  cin >> numPicks;
  if (numPicks < 1 or numPicks > pickFrom) {
    cout << "Input Error!" << endl;
    cout << "How many balls (1-" << pickFrom << ") will be drawn? ";
    cin >> numPicks;
  }
}

/*******************************************************************
 * computeWays                                                      *
 * Computes and returns the number of different possible sets       *
 * of k numbers that can be chosen from a set of n numbers.         *
 * The formula for this is     k!(n- k)!                            *
 *                             --------                             *
 *                                 n!                               *
 * Note that the computation is done in a way that does not require *
 * multiplying two factorials together. This is done to prevent any *
 * intermediate result becoming so large that it causes overflow.   *
 ********************************************************************/

double computeWays(int pickFrom, int numPicks) {
  double nFac = factorial(pickFrom);
  double nMinusKFac = factorial(pickFrom - numPicks);
  double kFac = factorial(numPicks);
  double ways = kFac * nMinusKFac / nFac;
  return ways;
}
/*******************************************************************
 * factorial                                                        *
 * This function computes factorials recursively.                   *
 *******************************************************************/

double factorial(int n) {
  if (n == 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}
