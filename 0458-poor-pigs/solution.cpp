class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // Step 1: Calculate total trials we can perform
        // Example: Agar 15 min me pig marta hai aur 60 min total hain, 
        // toh hum 60/15 = 4 trials kar sakte hain.
        int trials = minutesToTest / minutesToDie;
        
        int pigs = 0;
        
        // Step 2: The Core Concept of "States"
        // Ek pig ke paas (trials + 1) states hoti hain.
        // Kyunki pig ya toh trial 1 me marega, trial 2 me marega... ya aakhiri tak zinda bachega (+1 state).
        // Total unique combinations jo 'pigs' cover kar sakte hain = (trials + 1)^pigs
        // Hum tab tak pigs badhayenge jab tak total combinations total 'buckets' ke equal ya usse zyada na ho jayein.
        while(pow(trials + 1, pigs) < buckets) {
            pigs++;
        }
        
        // Step 3: Return the minimum number of pigs required
        return pigs;
    }
};
