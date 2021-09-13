#include<iostream>
#include<vector>

using namespace std;

vector<unsigned int> transformSequence(vector<unsigned int> seq, int n) {
	unsigned int setnBits = (uint32_t)(((uint64_t)1 << n) - 1), temp;
	int countPerByte = (32 / n);
	int resultSeqSize = seq.size() / countPerByte;
	resultSeqSize = (seq.size() % countPerByte == 0) ? resultSeqSize : resultSeqSize + 1;
	vector<unsigned int> result;

	for (int i = 0; i < resultSeqSize; i++) {
		temp = 0;
		for (int j = min((i + 1) * countPerByte, (int)seq.size()) - 1; j >= i * countPerByte; j--) {
			temp = (seq[j] & setnBits) | temp;
			temp = temp << n;
		}
		result.push_back(temp);
	}
	return result;
}

int main()
{
	unsigned int seqSize = 100, n, temp;
	vector<unsigned int> sequence;
	
	cout << "Enter n..  "; 
	cin >> n;
	
	cout << "Enter sequence of unsgined 32bit integers.." << endl;
	for (int i = 0; i < seqSize; i++){
		cin >> temp;
		sequence.push_back(temp);
	}

	vector<unsigned int> result = transformSequence(sequence, n);
	return 0;
}
