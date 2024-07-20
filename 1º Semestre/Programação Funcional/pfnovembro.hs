-- Aulas Pf Novembro
import Data.Char

-- Aula 3/11/21
merge1 :: Ord a => [a] ->  [a] -> [a]
-- ordena 2as listas ordenadas
merge1 [] y = y
merge1 x [] = x
merge1 (x:y) (a:b) | x <= a = x : merge1 y (a:b)
                   | otherwise = a : merge1 (x:y) b 



msort1 :: Ord a => [a] -> [a]
--- ordena 1a lista
msort1 [] = []
msort1 [x] = [x]
msort1 l = let (a,b) = parte l
           in merge1 (msort1 a) (msort1 b)                  
      where parte :: [a] -> ([a],[a])
            -- parte a lista a metade
            parte [] = ([],[])
            parte (h:t) = (h:s, p)
                where (p,s) = parte t



qsorte :: Ord a => [a] -> [a]
-- Ordena uma lista
qsorte [] = []
qsorte (h:t) = let mi = menores h t
                   ma = maiores h t
               in (qsorte mi) ++ [h] ++ (qsorte ma)
        

menores :: Ord a => a -> [a] -> [a]
menores x [] = []
menores x (h:t) | h <= x = h : menores x t
                | otherwise = menores x t 
            
maiores :: Ord a => a -> [a] -> [a]
maiores x [] = []
maiores x (h:t) | x >= h = maiores x t
                | otherwise = h : maiores x t 



menmai :: Ord a => a -> [a] -> ([a],[a])
-- vai criar a lista dos menores e dos maiores em apenas uma vez (Tupling) 
menmai x [] = ([],[])
menmai x (h:t) | x <= h = (a, h:b)
               | otherwise = (h:a, b)
        where (a,b) = menmai x t



-- Função soma toda xispas

somanormal :: [Int] -> Int 
somanormal [] = 0 
somanormal (x:y) = x + somanormal y

soma :: Num a => a -> [a] -> a
soma x [] = x
soma x (h:t) = soma (x+h) t


som :: Num a => [a] -> a
som l = soma 0 l



-- Aula 10/11/21
-- Funções de ordem superior

dobro :: Int -> Int 
dobro x = 2*x


dobrol :: [Int] -> [Int]
dobrol [] = []
dobrol (x:y) = (dobro x) : dobrol y


aplica :: (a->b) -> [a] -> [b]
aplica f [] = []
aplica f (x:y) = f x : aplica f y

-- -->

dobros :: [Int] -> [Int]
dobros l = aplica dobro l 


fica :: Int -> [a] -> [a]
-- fica só com os x primeiros elementos
fica 0 l = []
fica _ [] = []
fica x (h:t) = h : (fica (x-1) t)


digits :: String -> String 
-- fica só com os digitos
digits [] = []
digits (h:t) | isAlpha h = h : digits t
             | otherwise = digits t


filtro :: (a->Bool) -> [a] -> [a]
filtro x [] = []
filtro x (h:t) | x h = h : (filtro x t)
               | otherwise = filtro x t

-- -->
novodigito = filtro isAlpha 


-- Dá os numeros negativos
negs [] = []
negs (h:t) | h < 0 = h : negs t
           | otherwise = negs t


negsf = filter (<0)


-- Matrizes 
type Matriz = [Linha]
type Linha = [Float]


somaM :: Matriz -> Matriz -> Matriz
somaM [] [] = []
somaM (a:as) (b:bs) = (somaL a b) : somaM as bs
       where somaL :: Linha -> Linha -> Linha
             somaL [] [] = []
             somaL (x:xs) (y:ys) = x+y : somaL xs ys 


multe :: Float -> Matriz -> Matriz
multe e [] = []
multe e (l:ls) = (mel e l) : multe e ls
      where mel e l = map (e*) l


-- Aula 17/11

--Soma, Produto e Reverse com foldr
somaf l = foldr (+) 0 l

produtof l = foldr (*) 1 l

reversef l = foldr aux [] l
         where aux h t = t ++ [h]

-- foldr é defenido: fu:: (a->b) -> b -> [a] -> b
--                   fu f [] = []
--                   fu f (h:t) = f h : (foldr f t) 

-- Árvores Binárias 
data Abin a = Vazia | N a (Abin a)(Abin a) 
    
arv1 = N 4 (N 2 (N 3 Vazia Vazia)(Vazia))(N 10 Vazia Vazia)


tamanhod :: Abin a -> Int 
tamanhod Vazia = 0 
tamanhod (N r e d) = 1 + tamanhod e + tamanhod d


alturad :: Abin a -> Int 
alturad Vazia = 0
alturad (N r e d) = 1 + (max(alturad e)(alturad d))


elementosd :: Abin a -> Int 
elementosd Vazia = 0 
elementosd (N r e d) = 1 + ((elementosd e) + (elementosd d))


constroi :: [a] -> Abin a
constroi [] = Vazia
constroi (x:y) = N x (constroi y) Vazia


-- Aula Teórica 24/11

--constroia :: [a] -> Abin a
--constroia [] = Vazia
--constroia l = let c = div (lenght l) 2
--               (e, x:d) = splitAt c l
--             in N x (constroi e)(constroi d)
--  Dá erro, não sei construir direito 

-- Árvores Binárias de Procura 
procura :: Ord a => a -> Abin a -> Bool 
procura x Vazia = False 
procura x (N r e d) | x == r = True 
                    | x < r = procura x e
                    | x > r = procura x d


acrescenta :: Ord a => a -> Abin a -> Abin a 
acrescenta x Vazia = N x Vazia Vazia
acrescenta x (N r e d) | x <= r = N r (acrescenta x e) d
                       | x > r = N r e (acrescenta x d)


constroiabp :: Ord a => [a] -> Abin a
constroiabp [] = Vazia
constroiabp l = foldr acrescenta Vazia l


maior :: Abin a -> a
maior (N r e Vazia) = r
maior (N r e d) = maior d


semmaior :: Abin a -> Abin a 
semmaior (N r e Vazia) = e
semmaior (N r e d) = N r e (semmaior d)


--maiorsmaior :: Abin a -> (a, Abin a)
--maiorsmaior (N x e Vazia) = (x, e)
--maiorsmaior (N x e d) = (p, N x e q)
--                    where (p,q) = maiorsmaior d

-- Erro não estou a perceber porquê

--deleteabp :: a -> Abin a -> Abin a
--deleteabp x Vazia = Vazia
--deleteabp x (N r e d) | x == r = removeraiz (N r e d)
--                      | x < r = N r (deleteabp x e) d
--                      | x > r = N r e (deleteabp x d)
--       where removeraiz (N r Vazia d) = d
--             removeraiz (N r e Vazia) = e
--             removeraiz (N r e d) = N a e d
--                        where (a, e) = maiorsmaior e
-- Precisa da anterior              

data Rtree a = R a [Rtree a]

rtree = R 1 [R 2 [], R 3 []]

contanodos :: Rtree a -> Int 
contanodos (R n l) = 1 + sum (map contanodos l)




-- Relativamente a este ficheiro, as funções cuja resposta é uma Abin não funcionam pois pedem uma função do tipo print