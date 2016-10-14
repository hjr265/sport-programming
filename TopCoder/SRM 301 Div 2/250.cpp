// In the name of Allah, Most Gracious, Most Merciful

// TopCoder/SRM 301 Div 2/250
// Insertion Sort Count
// implementation
// http://community.topcoder.com/stat?c=problem_statement&pm=6224&rd=9822
// (InsertionSortCount) countMoves(vector<int>) int
// AC (185)

#include <vector>

using namespace std;

class InsertionSortCount {
public:
	int countMoves(vector<int> A) {
		int M = 0;
		vector<int> R(A.size()+1);
		R[0] = -1005;
		for(int i = 0; i < A.size(); ++i) {
			int N = A[i];
			for(int j = i; j >= 0; --j) if(R[j] < N) {
				--M;
				for(int k = i+1; k > j; --k)
					R[k] = R[k-1], ++M;
				R[j+1] = N;
				break;
			}
		}
		return M;
	}
};
