 # i n c l u d e   < s t d i o . h >  
 # i n c l u d e   < m a t h . h >  
  
 # d e f i n e   P I     3 . 1 4 1 5 9 2 6 5 3 5 8 9 7 9 3 2 3 8 4 6 2 6 4 3 3 8 3 2 7 9 5 0 2 8 8 4 1 9 7 1 6 9 3 9 9 3 7 5 1 0 	    
 # d e f i n e   P I 2   6 . 2 8 3 1 8 5 3 0 7 1 7 9 5 8 6 4 7 6 9 2 5 2 8 6 7 6 6 5 5 9 0 0 5 7 6 8 3 9 4 3 3 8 7 9 8 7 5 0 2 1  
 # d e f i n e   N   2 5 6 	 	 	 	    
 # d e f i n e   M   8 	 	 	 	        
 # d e f i n e   N p a r t 2   1 2 8 	 	 	  
 # d e f i n e   N p a r t 4   6 4 	 	 	  
 # d e f i n e   F F T _ R E S U L T ( x )   	 ( s q r t ( d a t a [ x ] . r e a l * d a t a [ x ] . r e a l + d a t a [ x ] . i m a g * d a t a [ x ] . i m a g ) )  
 # d e f i n e   I F F T _ R E S U L T ( x ) 	 ( d a t a [ x ] . r e a l / N )  
 t y p e d e f   f l o a t   E l e m T y p e ; 	 	  
  
 t y p e d e f   s t r u c t 	 	 	 	  
 {  
 	 E l e m T y p e   r e a l ,   i m a g ;  
 } c o m p l e x ;  
  
 c o m p l e x   d a t a [ N ] ;  
 E l e m T y p e   S I N _ T A B L E [ N p a r t 4   +   1 ] ;  
  
  
 v o i d   I n p u t D a t a ( v o i d )  
 {  
 	 i n t   i ;  
 	 f o r   ( i   =   0 ;   i   <   N ;   i + + )  
 	 {  
 	 	 d o u b l e   t   =   i * 1 . 0   /   N ;  
 	 	 d a t a [ i ] . r e a l   = 2   +   3   *   c o s ( 2   *   P I   *   5 0   *   t   -   P I   *   3 0   /   1 8 0 )   +   1 . 5 * c o s ( 2   *   P I   *   7 5   *   t   +   P I   *   9 0   /   1 8 0 ) ;  
 	 	 d a t a [ i ] . i m a g   =   0 ;  
 	 }  
 }  
  
 v o i d   C R E A T E _ S I N _ T A B L E ( v o i d )  
 {  
 	 i n t   i   =   0 ;  
 	 f o r   ( i   =   0 ;   i   < =   N p a r t 4 ;   i + + )  
 	 {  
 	 	 S I N _ T A B L E [ i ]   =   s i n ( P I * i   /   N p a r t 2 ) ; / / S I N _ T A B L E [ i ]   =   s i n ( P I 2 * i / N ) ;  
 	 }  
 }  
  
 E l e m T y p e   S i n _ f i n d ( E l e m T y p e   x )  
 {  
 	 i n t   i   =   ( i n t ) ( N * x ) ;  
 	 i   =   i   > >   1 ;  
 	 i f   ( i   >   N p a r t 4 )  
 	 {  
 	 	 i   =   N p a r t 2   -   i ; / / i   =   i   -   2 * ( i - N p a r t 4 ) ;  
 	 }  
 	 r e t u r n   S I N _ T A B L E [ i ] ;  
 }  
 E l e m T y p e   C o s _ f i n d ( E l e m T y p e   x )  
 {  
 	 i n t   i   =   ( i n t ) ( N * x ) ;  
 	 i   =   i   > >   1 ;  
 	 i f   ( i   <   N p a r t 4 )  
 	 {    
 	 	 / / i   =   N p a r t 4   -   i ;  
 	 	 r e t u r n   S I N _ T A B L E [ N p a r t 4   -   i ] ;  
 	 }  
 	 e l s e / / i > N p a r t 4   & &   i < N / 2  
 	 {  
 	 	 / / i   =   i   -   N p a r t 4 ;  
 	 	 r e t u r n   - S I N _ T A B L E [ i   -   N p a r t 4 ] ;  
 	 }  
 }  
  
 / / ? ? ?    
 v o i d   C h a n g e S e a t ( c o m p l e x   * D a t a I n p u t )  
 {  
 	 i n t   n e x t V a l u e ,   n e x t M ,   i ,   k ,   j   =   0 ;  
 	 c o m p l e x   t e m p ;  
  
 	 n e x t V a l u e   =   N   /   2 ;                                      
 	 n e x t M   =   N   -   1 ;  
 	 f o r   ( i   =   0 ;   i   <   n e x t M ;   i + + )  
 	 {  
 	 	 i f   ( i   <   j ) 	 	 	 	 	  
 	 	 {  
 	 	 	 t e m p   =   D a t a I n p u t [ j ] ;  
 	 	 	 D a t a I n p u t [ j ]   =   D a t a I n p u t [ i ] ;  
 	 	 	 D a t a I n p u t [ i ]   =   t e m p ;  
 	 	 }  
 	 	 k   =   n e x t V a l u e ;                                  
 	 	 w h i l e   ( k   < =   j ) 	 	 	 	  
 	 	 {  
 	 	 	 j   =   j   -   k ; 	 	 	 	 	  
 	 	 	 k   =   k   /   2 ; 	 	 	 	 	  
 	 	 }  
 	 	 j   =   j   +   k ; 	 	 	 	 	 	  
 	 }  
 }  
  
 v o i d   F F T ( v o i d )  
 {  
 	 i n t   L   =   0 ,   B   =   0 ,   J   =   0 ,   K   =   0 ;  
 	 i n t   s t e p   =   0 ,   K B   =   0 ;  
 	 / / E l e m T y p e   P = 0 ;  
 	 E l e m T y p e   a n g l e ;  
 	 c o m p l e x   W ,   T e m p _ X X ;  
  
 	 C h a n g e S e a t ( d a t a ) ; / / ? ? ?    
 	 / / C R E A T E _ S I N _ T A B L E ( ) ;  
 	 f o r   ( L   =   1 ;   L   < =   M ;   L + + )  
 	 {  
 	 	 s t e p   =   1   < <   L ; / / 2 ^ L  
 	 	 B   =   s t e p   > >   1 ; / / B = 2 ^ ( L - 1 )  
 	 	 f o r   ( J   =   0 ;   J   <   B ;   J + + )  
 	 	 {  
 	 	 	 / / P   =   ( 1 < < ( M - L ) ) * J ; / / P = 2 ^ ( M - L )   * J    
 	 	 	 a n g l e   =   ( d o u b l e ) J   /   B ; 	 	 	  
 	 	 	 W . i m a g   =   - S i n _ f i n d ( a n g l e ) ; 	 	 / / ? C + + ? � ? ? ? ? ? ?� i n l i n e    
 	 	 	 W . r e a l   =   C o s _ f i n d ( a n g l e ) ; 	 	 / / ? C + + ? � ? ? ? ? ? ?� i n l i n e    
 	 	 	 / / W . r e a l   =     c o s ( a n g l e * P I ) ;  
 	 	 	 / / W . i m a g   =   - s i n ( a n g l e * P I ) ;  
 	 	 	 f o r   ( K   =   J ;   K   <   N ;   K   =   K   +   s t e p )  
 	 	 	 {  
 	 	 	 	 K B   =   K   +   B ;  
 	 	 	 	 / / T e m p _ X X   =   X X _ c o m p l e x ( d a t a [ K B ] , W )  
 	 	 	 	 T e m p _ X X . r e a l   =   d a t a [ K B ] . r e a l   *   W . r e a l   -   d a t a [ K B ] . i m a g * W . i m a g ;  
 	 	 	 	 T e m p _ X X . i m a g   =   W . i m a g * d a t a [ K B ] . r e a l   +   d a t a [ K B ] . i m a g * W . r e a l ;  
  
 	 	 	 	 d a t a [ K B ] . r e a l   =   d a t a [ K ] . r e a l   -   T e m p _ X X . r e a l ;  
 	 	 	 	 d a t a [ K B ] . i m a g   =   d a t a [ K ] . i m a g   -   T e m p _ X X . i m a g ;  
  
 	 	 	 	 d a t a [ K ] . r e a l   =   d a t a [ K ] . r e a l   +   T e m p _ X X . r e a l ;  
 	 	 	 	 d a t a [ K ] . i m a g   =   d a t a [ K ] . i m a g   +   T e m p _ X X . i m a g ;  
 	 	 	 }  
 	 	 }  
 	 }  
 }  
 / / I F F T ? ? ? ? ?    
 v o i d   I F F T ( v o i d )  
 {  
 	 i n t   L   =   0 ,   B   =   0 ,   J   =   0 ,   K   =   0 ;  
 	 i n t   s t e p   =   0 ,   K B   =   0 ;  
 	 / / E l e m T y p e   P = 0 ;  
 	 E l e m T y p e   a n g l e ;  
 	 c o m p l e x   W ,   T e m p _ X X ;  
  
 	 C h a n g e S e a t ( d a t a ) ; / / ? ? ?    
 	 / / C R E A T E _ S I N _ T A B L E ( ) ;  
 	 f o r   ( L   =   1 ;   L   < =   M ;   L + + )  
 	 {  
 	 	 s t e p   =   1   < <   L ; / / 2 ^ L  
 	 	 B   =   s t e p   > >   1 ; / / B = 2 ^ ( L - 1 )  
 	 	 f o r   ( J   =   0 ;   J   <   B ;   J + + )  
 	 	 {  
 	 	 	 / / P   =   ( 1 < < ( M - L ) ) * J ; / / P = 2 ^ ( M - L )   * J    
 	 	 	 a n g l e   =   ( d o u b l e ) J   /   B ; 	 	 	  
  
 	 	 	 W . i m a g   =   S i n _ f i n d ( a n g l e ) ; 	 	    
 	 	 	 W . r e a l   =   C o s _ f i n d ( a n g l e ) ; 	 	  
 	 	 	 / / W . r e a l   =     c o s ( a n g l e * P I ) ;  
 	 	 	 / / W . i m a g   =   - s i n ( a n g l e * P I ) ;  
 	 	 	 f o r   ( K   =   J ;   K   <   N ;   K   =   K   +   s t e p )  
 	 	 	 {  
 	 	 	 	 K B   =   K   +   B ;  
 	 	 	 	 / / T e m p _ X X   =   X X _ c o m p l e x ( d a t a [ K B ] , W ) ;  
 	 	 	 	 T e m p _ X X . r e a l   =   d a t a [ K B ] . r e a l   *   W . r e a l   -   d a t a [ K B ] . i m a g * W . i m a g ;  
 	 	 	 	 T e m p _ X X . i m a g   =   W . i m a g * d a t a [ K B ] . r e a l   +   d a t a [ K B ] . i m a g * W . r e a l ;  
  
 	 	 	 	 d a t a [ K B ] . r e a l   =   d a t a [ K ] . r e a l   -   T e m p _ X X . r e a l ;  
 	 	 	 	 d a t a [ K B ] . i m a g   =   d a t a [ K ] . i m a g   -   T e m p _ X X . i m a g ;  
  
 	 	 	 	 d a t a [ K ] . r e a l   =   d a t a [ K ] . r e a l   +   T e m p _ X X . r e a l ;  
 	 	 	 	 d a t a [ K ] . i m a g   =   d a t a [ K ] . i m a g   +   T e m p _ X X . i m a g ;  
 	 	 	 }  
 	 	 }  
 	 }  
 }  
  
 i n t   m a i n ( i n t   a r g c ,   c h a r   * a r g v [ ] )  
 {  
 	 i n t   i   =   0 ;  
 	 F I L E   * p F i l e   =   f o p e n ( " . . / 2 . t x t " ,   " w b + " ) ;  
 	 C R E A T E _ S I N _ T A B L E ( ) ; 	  
  
 	 I n p u t D a t a ( ) ; 	  
  
 	 F F T ( ) ; 	 	 	 	  
  
 	 f o r   ( i   =   0 ;   i   <   N ;   i + + )  
 	 {  
 	 	 d o u b l e   t e m p   =   F F T _ R E S U L T ( i ) ;  
 	 	 f w r i t e ( & t e m p ,   s i z e o f ( d o u b l e ) ,   1 ,   p F i l e ) ;  
 	 }  
 	 f c l o s e ( p F i l e ) ;  
 	 r e t u r n   0 ;  
 }  
