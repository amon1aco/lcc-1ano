-- Ficha 2
import Data.Char

--1
{-
--a
fun :: [Double] -> Double
fun [] = 0
fun (a:b) = a^2 + fun b

    Vai ler assim:
fun [2,3,5,1] = fun (2:[3,5,1]) = 2^2 + fun [3,5,1] = 4 + fun (3:[5,1]) = ... = 39 + 0 = 39

--b
fun :: [Int] -> [Int]
fun [] = []
fun (a:b) = if (mod a 2) == 0 then a : (fun tb)
                              else (fun b)
    Vai ler assim: 
fun [8,5,12] = fun (8:[5,12]) = 8 : fun [5,12] = 8 : fun (5:[12]) = ... = 8:12:[] = [8,12]

--c
fun (x:y:t) = fun t
fun [x] = []
fun [] = []
    Vai ler assim:
fun [1,2,3,4,5] = fun (1:2:[3,4,5]) = fun [3,4,5] = fun (3:4:[5]) = fun [5] = []

--d
fun l = g [] l
g l [] = l
g l (h:t) = g (h:l) t
    Vai ler assim:
fun "otrec" = g [] "otrec" = g ['o'] "trec" = g "to" "rec" = ... = "certo"
-}
--2 
--a
dobros :: [Float] -> [Float]
dobros [] = []
dobros (x:y) = 2 * x : dobros y

--b
numqocorre :: Char -> String -> Int
numqocorre _ [] = 0
numqocorre x (h:t) | x == h = 1 + numqocorre x t
                   | otherwise = numqocorre x t

--c
positivos :: [Int] -> Bool
positivos [] = True 
positivos (x:y) | x > 0 = positivos y
                | otherwise = False

--d
sopos :: [Int] -> [Int]
sopos [] = []
sopos (x:y) | x > 0 = x : sopos y
            | otherwise = sopos y

--e
somaneg :: [Int] -> Int
somaneg [] = 0
somaneg (x:y) | x < 0 = x + somaneg y
              | otherwise = somaneg y

--f
tresult :: [a] -> [a]
tresult [] = []
tresult [x,y] = [x,y]
tresult [x,y,z] = [x,y,z]
tresult (x:y) = tresult y

--g
segundos :: [(a,b)] -> [b]
segundos [] = []
segundos ((x,y):z) = y : segundos z

--h
nosp :: (Eq a) => a -> [(a,b)] -> Bool
nosp _ [] = False
nosp x ((a,b):c) | x == a = True
                 | otherwise = nosp x c

--i
sumt :: (Num a, Num b, Num c) => [(a,b,c)] -> (a,b,c)
sumt [] = (0,0,0)
sumt ((a,b,c):t) = (a + p,b + v,c + h)
         where (p,v,h) = sumt t

--3
--a
sodigitos :: [Char] -> [Char]
sodigitos [] = []
sodigitos (a:b) | isDigit a = a : sodigitos b
                | not $ isDigit a = sodigitos b
               
--b
minusculas :: [Char] -> Int
minusculas [] = 0
minusculas (a:b) | isLower a = 1 + minusculas b
                 | otherwise = minusculas b

--c 
nums :: String -> [Int]
nums [] = []
nums (a:b) | isDigit a = digitToInt a : nums b
           | otherwise = nums b

    -- Estão todas certas, mas não consigo testar nenhuma e não sei porque :/

--4
type Polinomio = [Monomio]
type Monomio = (Float,Int)

-- exemplo: [(2,3), (3,4), (5,3), (4,5)]

--a
conta :: Int -> Polinomio -> Int
conta _ [] = 0
conta x ((a,b):c) | x == b = 1 + conta x c
                  | otherwise = conta x c

--b
grau :: Polinomio -> Int
grau [] = 0
grau ((a,b):c) | b < grau c = grau c
               | otherwise = b

--c 
selgrau :: Int -> Polinomio -> Polinomio
selgrau _ [] = []
selgrau x ((a,b):c) | x == b = (a,b) : selgrau x c
                    | otherwise = selgrau x c

--d
--deriv :: Polinomio -> Polinomio
deriv [] = []
deriv ((a,b):c) = (a*b,b-1) : deriv c
    -- Está a funcionar direitinho mas não funciona com o tipo pedido..

--e 
calcula :: Float -> Polinomio -> Float
calcula x [] = 0
calcula x ((a,b):c) = a * (x^b) + calcula x c

--f
simp :: Polinomio -> Polinomio
simp [] = []
simp ((a,b):c) | b == 0 = simp c
               | otherwise = (a,b) : simp c

--g
mult :: Monomio -> Polinomio -> Polinomio
mult (_,_) [] = []
mult (x,y) ((a,b):c) = (x*a, y+b) : mult (x,y) c

--h
somamonomio ((a, b):[]) = (a, b)
somamonomio ((a, b):(c, _):xs) = somamonomio ((a+c, b):xs)

graus [] = []
graus (x:xs) = if elem x xs then graus xs else x : graus xs

normaliza :: Polinomio -> Polinomio
normaliza [] = []
normaliza l = [ somamonomio (selgrau x l) | x <- aux]
  where aux = graus [ b | (a, b) <- l]

--i
soma :: Polinomio -> Polinomio -> Polinomio
soma l [] = l
soma [] l = l
soma p1 p2 = normaliza (p1 ++ p2)

--j
produto :: Polinomio -> Polinomio -> Polinomio
produto [] _ = []
produto _ [] = []
produto ((a,b):c) ((x,y):z) = normaliza ((a*x,b+y) : produto ((a,b):c) z ++ produto c ((x,y):z))

--k
ordena :: Polinomio -> Polinomio
ordena [] = []
ordena (x:y) = bota x (ordena y)

bota :: Monomio -> Polinomio -> Polinomio
bota (a,b) [] = [(a,b)]
bota (x,y) ((a,b):c) | y > b     = (x,y) : (a,b) : c
                     | otherwise = (a,b) : bota (x,y) c

--l
equiv :: Polinomio -> Polinomio -> Bool
equiv p1 p2 = normaliza p1 == normaliza p2 