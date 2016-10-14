// In the name of Allah, Most Gracious, Most Merciful

// TopCoder/SRM 275 Div 1/250
// Inverse Haar 1D
// implementation
// http://community.topcoder.com/stat?c=problem_statement&pm=5896&rd=8072
// (InverseHaar1D) transform(vector<int>, int) vector<int>
// AC (182)

#include <vector>

using namespace std;

class InverseHaar1D {
public:
	vector<int> transform(vector<int> transformedData, int L) {
		vector<int> result(transformedData.size(), 0);
		while(L) {
			for(int i = 0; i < transformedData.size(); ++i)
				result[i] = transformedData[i];
			for(int i = 0; i < transformedData.size()/(1<<L); ++i) {
				int A = transformedData[i],
					B = transformedData[transformedData.size()/(1<<L)+i];
				result[2*i] = (A+B)/2;
				result[2*i+1] = A-result[2*i];
			}
			transformedData = result;
			--L;
		}
		return result;
	}
};
