class Solution {
public:
    bool traverseBox(vector<vector<char>>& board , int sr , int er , int sc , int ec){
        unordered_set<char>st ;
        for(int r = sr;r<=er ; r++){
            
            for(int c = sc ; c<=ec ; c++){
                if(board[r][c] == '.'){
                    continue ;
                }

                if(st.find(board[r][c]) != st.end()){
                    return false ;
                }

                st.insert(board[r][c]) ;
            }
        }

        

        return true ;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        //rows = 9 
        //cols = 9 

        //vaalidate rows 
        for(int r = 0 ;r<9 ; r++){
            unordered_set<char>st ;
            for(int c = 0 ; c<9 ; c++){
                if(board[r][c] == '.'){
                    continue ;
                }

                if(st.find(board[r][c]) != st.end()){
                    return false ;
                }

                st.insert(board[r][c]) ;
            }
        }

        //vaalidate col
        for(int c = 0 ;c<9 ; c++){
            unordered_set<char>st ;
            for(int r = 0 ; r<9 ; r++){
                if(board[r][c] == '.'){
                    continue ;
                }

                if(st.find(board[r][c]) != st.end()){
                    return false ;
                }

                st.insert(board[r][c]) ;
            }
        }

        //validate each 3*3 box 

        for(int sr = 0 ; sr<9 ; sr+=3){
            int er = sr + 2 ;

            for(int sc = 0 ; sc<9 ; sc+=3){
                int ec = sc + 2 ;

                if(!traverseBox(board , sr , er , sc , ec)){
                    return false ;
                }
            }
        }

        return true ;

    }
};
