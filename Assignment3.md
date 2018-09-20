1. If Mathematics is easy, then Homework gets done and if it is sunny, then camping is fun.

2. (S ^ H)->(M v C)

3. 
A	B	~A	~B	~B -> ~A     ~B -> A	(~B -> A) -> B 	 (~B -> ~A) -> ((~B -> A) -> B)
T	T	F	  F	      T	            T	      	T   		                  T
T	F	F 	T     	F	            T		      F		                      T
F	T	T	  F	      T	            T     		T                     		T
F	F	T	  T	      T	            F		      T		                      T

It is a tautology.


A	B	~A	~B	A -> B	B -> ~A	((A -> B) ^ (B -> ~A))	((A -> B) ^ (B -> ~A)) -> A

T	T	F	F	T	F	F			T

T	F	F	T	F	T	F			T

F	T	T	F	T	T	T			F

F	F	T	T	T	T	T			F

It is neither a tautology or a contradiction.
4. (p ∧ q) → r <=> p → (q → r )
                   p' v (q -> r)    (Implication)
                   p' v (q' v r)    (Implication)
   (p^q)' v r                       (Implication)
   (p' v q') v r	                  (De Morgan's)
   (p' v q') v r <=> (p' v q') v r  (Associative)
   
   (q ∨ r ) → p <=> (q → p)∧(r → p)
                    (q' v p) ^ (r' v p)      (Implication)
   (q v r)' v p                              (Implication)
   (q' ^ r') v p                             (De Morgan's)
   (q' v p) ^ (r' v p) <=> (q' v p^ (r' v p) (Distributive)           
  
  Part 4:
  Translate into English: ∃x∀y∀z(City(x) ∧ Traveler (y) ∧ Lives(z,x)) → (Loves(y,x)∧ ¬Loves(z,x))
  
  There exists some cities in which every traveler loves the city, and every person who lives in it does not love the city.
  ∀x∀y(Traveler(x) ^ City(y) ^ Lives (x,y) -> ¬Loves(x,y)
   
    
   
   
   
   
   
   









                
                
   
    
   
   
   
   
   
   









