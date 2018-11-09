#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Combinations{

	vector<char> letters;
	int   comb;
	list<char> combination;

	// Helper functions are implemented as private
	// Helper function for recursion
	void combinations_helper(vector<char> letters, int level);

	// Helper function for slicing vectors
	vector<char> slice_vector(vector<char> letters, int begin);

	// Helper function to print each combination
	void print_combination();

	public:

		// Constructor
		Combinations(vector<char> letters, int comb);

		// Find combinations of given letters
		void find_combinations();
};

Combinations::Combinations(vector<char> letters, int comb){
	this->letters  = letters;
	this->comb = comb;
}

vector<char> Combinations::slice_vector(vector<char> letters, int begin){

	vector<char> new_letters;
	copy(letters.begin() + begin, letters.end(), back_inserter(new_letters)); 

	return new_letters;
}

void Combinations::combinations_helper(vector<char> letters, int level){

	if(level == 0){
		print_combination();
		this->combination.pop_back();
	}
	else{
		for(int i = 0; i < letters.size(); i++){
			this->combination.push_back(letters[i]);
			combinations_helper(slice_vector(letters, i + 1), level - 1);
		}

		if(this->combination.size() != 0)
			this->combination.pop_back();
	}

}

void Combinations::find_combinations(){

		combinations_helper(letters, this->comb);
		this->combination.clear();	
}

void Combinations::print_combination(){

	for(list<char>::iterator it = this->combination.begin(); 
		it != this->combination.end(); it++){
		cout << *it;
	}
	
	cout << endl;	
}

int main(){

	vector<char> letters = {'A', 'B', 'C', 'D'};
	int k = 2;

	Combinations combs(letters, k);
	combs.find_combinations();

	return 0;
}