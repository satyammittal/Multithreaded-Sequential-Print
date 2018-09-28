    #include <iostream>
    #include <string>
    #include <random>
     
    int main() {
    	std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
     
    	/* Define Ranges Here */
        std::uniform_int_distribution<> N_length(1, 200);
    	std::uniform_int_distribution<> N_threads(1, 15);	
    	std::uniform_int_distribution<> N_output(1, 200);
    	std::uniform_int_distribution<> char_array(97, 122);
     
    	int test_cases=100; // test cases
    	//Note : N_charblock is dynamically generated in line 21
     
     
    	while (test_cases--) {
    		int cur_length=N_length(gen);
    		std::uniform_int_distribution<> N_charblock(1, cur_length);
     
    		std::string s="";
    		for (int i=0;i<cur_length;i++) s=s+((char)char_array(gen));
     
    		std::cout<<s<<" "<<N_threads(gen)<<" "<<N_output(gen)<<" "<<N_charblock(gen)<<"\n";
     
    	}
     
    	return 0;
    }