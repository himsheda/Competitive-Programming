# lets define snake algo:
# you are given a binary matrix of nxm and iterations T
# in each iteration our goal is to find a matrix if the form
# 1 0   or 0 1
# 0 1         1 0
# the algo goes as follows :
# pick a row and a coloumn r1,c1
# then without loss of generality lets say we find M[r1][c1] =1 then we choose all the coloumns in the row r1 which has 0 in it. from these coloumns pick a coloum randomly say c2. then from that coloum c2  choose all the rows with 0  and from them choose a row r3 randomly. 


# now  check  if M[r3][c1] is equal to 0. if not then pick a coloumn c4 from thr matrix M[r3][:] with zeros . the delete the c1. and check if M[r1][c4]==1 if not then choose r4  similarly and delet r1. and check M[r4][c2] ==0 . repeate thsi step untill the condition is satisfied. 


# if the matrix found then flop the matrix that is 
# flip 1 0
# 0 1  to 0 1
# 1 0. 

# the above is only one iteration. 
# then for each iteration do the same thing i.e T times and store the matrix in a list
# write the above algo in R

rectangle_loop <- function(A, T, chain=FALSE) {
    if(chain){
        intermediate_matrices <- list(A) 
        swap_counts <- vector("integer", length = T+1)
        swap_counts[1] <- 0
    }
    pattern1 <- matrix(c(1, 0, 0, 1), nrow = 2, byrow = TRUE)
    pattern2 <- matrix(c(0, 1, 1, 0), nrow = 2, byrow = TRUE)
    total_swaps <- 0
    for (t in 1:T) {
        # Choose one row and one column uniformly at random
        r1 <- sample(1:nrow(A), 1)
        c1 <- sample(1:ncol(A), 1)
        
        swaps_made <- 0
        
        if (A[r1, c1] == 1) {
            zero_cols <- as.vector(which(A[r1, ] == 0))
            
            if (length(zero_cols) > 0) {
                if(length(zero_cols)==1)
                    c2 <- zero_cols
                else 
                    c2<- sample(zero_cols,1)
                
                one_rows <- as.vector(which(A[, c2] == 1))
                if (length(one_rows) > 0) {
                    if(length(one_rows)==1)
                        r2 <- one_rows
                    else 
                        r2<- sample(one_rows,1)
                    if(A[r2,c1]==0){
                        A[c(r1,r2),c(c1,c2)] <- pattern2
                        
                        swaps_made <- 1
                    }
                }
            }
        } 
        else {
            
        }
        
        if(chain){
            intermediate_matrices[[t + 1]] <- A
            swap_counts[t+1] <- swaps_made
        }
        else{
            total_swaps <- total_swaps + swaps_made
        }
        
    }
    if(chain)
        return(list(intermediate_matrices, swap_counts))
    else
        return(total_swaps)
}