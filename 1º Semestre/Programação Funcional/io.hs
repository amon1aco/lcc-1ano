-- IOs Treino
import Data.Char

import System.Random

    {-
hw :: IO ()
hw = putStrLn "Hello World"


greet :: IO ()
greet = do 
    putStrLn "Whats is your name?"
    name <- getLine 
    putStrLn ("Hello " ++ name ++ ".")

greet1 :: IO ()
greet1 = do 
    putStrLn "What is your name?"
    name <- getLine 
    let uname = map toUpper name   
    putStrLn ("Hello " ++ uname ++ ".")
   

main :: IO ()
main = do 
    i <- getLine 
    if i /= "quit" then do 
        putStrLn ("Input: " ++ i)
        main 
    else 
        return ()


count :: Int -> Int -> IO ()
count n m = do 
    putStrLn (show n)
    if n < m then
        do count (n+1) m
    else 
        return ()


daola :: IO ()
daola = do 
    putStrLn ("Quem é que eu tenho que cumprimentar?")
    n <- getLine 
    putStrLn ("Olá " ++ n ++ "!")


fatorialIO :: IO ()
fatorialIO = do 
    putStrLn ("Digite um numero!")
    n <- getLine 
    putStrLn ("O resultado é: ")
    print (fat (read n))

fat :: Int -> Int 
fat 0 = 1 
fat n = n * fat (n-1)


soma :: IO ()
soma = do 
    putStrLn ("Digite um numero!")
    n1 <- getLine 
    putStrLn ("Digite outro numero!")
    n2 <- getLine 
    print ("A soma de " ++ n1 ++ "+" ++ n2 ++ " e:") 
    putStrLn (show (read n1 + read n2))


-- // -- 
inits :: [a] -> [[a]]
inits (a:b) = reverse (initi (a:b))

initi :: [a] -> [[a]]
initi [] = [[]]
initi (a:b) = (a:b) : initi (removelast (a:b))

removelast :: [a] -> [a]
removelast [] = []
removelast [a] = []
removelast (a:b) = a : removelast b


tails :: [a] -> [[a]]
tails [] = [[]]
tails (a:b) = (a:b) : tails (removehead (a:b))

removehead :: [a] -> [a]
removehead [a] = []
removehead (a:b) = b


fib :: Int -> Int 
fib 0 = 0 
fib 1 = 1 
fib n = fib (n-1) + fib (n-2)

primfib :: Int -> Int 
primfib x = fibaux x 0 1

fibaux :: Int -> Int -> Int -> Int 
fibaux 0 n _ = n 
fibaux x y z = fibaux (x-1) (z) (y+z)


transposta :: [[a]] -> [[a]]
transposta ([]:_) = []
transposta x =  map head x : transposta (map tail x)


type ConjInt = [Intrevalo]
type Intrevalo = (Int,Int)

elems :: ConjInt -> [Int]
elems [] = []
elems ((a,b):c) | a < b = a : elems ((a+1,b):c) 
                | a == b = a : elems c

geracon :: [Int] -> ConjInt
geracon [] = []
geracon (a:b) = acumulador (0,0) (a:b)

acumulador :: (Int, Int) -> [Int] -> [(Int, Int)]
acumulador (a,b) [] = [(a,b)]
acumulador (a,b) (x:y) | b+1 /= x = (a,b) : acumulador (x,x) y 
                       | b+1 == x = acumulador (a,b+1) y


gera :: IO ()
gera = do 
    putStrLn ("MEN, BOTA ME AI A LISTA DE INTS Q EU GERO O CONJUNTO")
    x <- getLine 
    putStrLn ("TA AI BRO")
    print (geracon (read x))


sorton :: Ord b => (a->b) -> [a] -> [a]
sorton f [] = []
sorton f (a:b) = insere f a (sorton f b)


insere :: Ord b => (a->b) -> a -> [a] -> [a]
insere f x [] = [x]
insere f x (a:b) | f x < f a = x : a : b 
                 | f x >= f a = a : insere f x b

            

data Seq a = Nil | Cons a (Seq a) | App (Seq a) (Seq a) 
  --  deriving Show

se = (App (App (Cons 7 (Cons 5 Nil)) (Cons 1 Nil)))


firstseq :: Seq a -> a 
firstseq (Cons x _)  = x  
firstseq (App Nil x) = firstseq x
firstseq (App x _)   = firstseq x

        --Os ultimos 2 parametros tem de ter esta mesma ordem!

dropseq :: Int -> Seq a -> Seq a
dropseq 0 x = x 
dropseq n Nil = Nil 
dropseq n (Cons a s) = dropseq (n-1) s 
dropseq n (App s s1) | n > nx = dropseq (n-1) s1
                     | n == nx = s1 
                     | n < nx = (App (dropseq n s)s1)
        where nx = contacons s 

contacons :: Seq a -> Int 
contacons Nil = 0 
contacons (Cons a x) = 1 + contacons x 
contacons (App s s1) = contacons s + contacons s1


instance Show a => Show (Seq a) where 
    show x = "<<" ++ sho x ++ ">>"


sho :: Show a => Seq a -> String 
sho (Cons a s) = (show a) ++ "," ++ (sho s)
sho (App  a s) = (sho a) ++ "," ++ (sho s)
sho Nil = ""

 



type Mat a = [[a]]

mat = [[6,7,2],[1,5,9],[8,3,4]]

getelem :: Mat a -> IO a
getelem mat = do
    let (l,c) = (length mat, length (head mat))
    randLine <- randomRIO (0,l-1)
    randRow <- randomRIO (0,c-1)
    return $ (mat !! randLine) !! randRow



digit :: String -> (String,String)
digit [] = ([],[])
digit (a:b) | isDigit a = (d ++ [a],c)
            | isAlpha a = (d,c ++ [a])
        where (d,c) = digit b

digitprim :: String -> (String,String)
digitprim l = foldr (\x (ds,as) -> if isDigit x then (ds ++ [x],as) else (ds,as ++ [x])) ([],[]) l 



data BTree a = Empty | Node a (BTree a) (BTree a)
    deriving Show   

bt = Node (1,3) (Node (3,4) Empty Empty) 
                (Node (4,5) (Node (3,1) Empty Empty) Empty)

lookupap :: Ord a => a -> BTree (a,b) -> Maybe b 
lookupap _ Empty = Nothing 
lookupap x (Node (a,b) c d) | x == a = Just b 
                            | x < a = lookupap x c 
                            | x > a = lookupap x d

zipwbt :: (a -> b -> c) -> BTree a -> BTree b -> BTree c 
zipwbt f Empty _ = Empty 
zipwbt f _ Empty = Empty 
zipwbt f (Node a b c) (Node d e g) = Node (f a d) (zipwbt f b e) (zipwbt f c g)



data Contacto = Casa Integer 
              | Trab Integer 
              | Tlm Integer 
              | Email String 
        deriving Show 
type Nome = String 
type Agenda = [(Nome,[Contacto])]

ag = [("jose", [Casa 3041, Trab 342908, Email "ruhjgr"]), ("mario", [Casa 8234, Tlm 32894, Email "afe"])]

acres :: Nome -> String -> Agenda -> Agenda 
acres [] [] f = f 
acres _ _ [] = []
acres n s ((nome,(c:o)):r) | n == nome = ((nome,(c:o) ++ [Email s]):r)
                           | otherwise = ((nome,(c:o)): acres n s r)

vermail :: Nome -> Agenda -> Maybe [String]
vermail n [] = Nothing 
vermail n ((nome,c):r) | n == nome = Just (aux c)           -- nsei pk n funciona. acho so q a funcao n gosta de mim.
                           | otherwise = vermail n r 

aux :: [Contacto] -> [Contacto]
aux [] = []
aux (c:o) = case c of 
                   Email c -> Email c : aux o
                   _  -> aux o


consulta :: [Contacto] -> ([Integer ], [String])
consulta [] = ([],[])
consula ((n,(c:o))) = (aux1, aux2)

aux1 :: [Contacto] -> [Contacto]
aux1 [] = []
aux1 (c:o) = case c of 
                    Tlm c -> Tlm c : aux1 o 
                    Trab c -> Trab c : aux1 o 
                    _ -> aux1 o 

aux2 :: [Contacto] -> [String]
aux2 [] = []
aux2 (c:o) = case c of 
                   Email c -> [c] ++  aux2 o
                   _  -> aux2 o       


consultaio :: Agenda -> IO ()
consultaio ag = do 
    putStrLn "Escreva um nome: "
    x <- getLine 
    let cc = uu x ag
    print cc                    -- nem sei o q dizer relativamente a esta merda, quer dizer deixa me dar load e depois reclama do print fse

uu :: Nome -> Agenda -> [Contacto]
uu n [] = []
uu n ((no,l):c) = if n == no then l else uu n c 


rev :: [a] -> [a]
rev l = foldl (flip (:)) [] l

prefixes :: [a] -> [[a]]
prefixes l = foldr (\x acc -> [x] : (map ((:) x)acc)) [[]] l


data Trie a = Leaf a | Node a [Trie a] 
  --  deriving Show 

t = 
    Node 1 [
        Node 2
            [Leaf 3, Leaf 4],
        Node 5 
            [Node 5
            [Leaf 7 ]]]
    
f :: (b -> a -> b) -> b -> Trie a -> b
f c b (Leaf a) = c b a 
f c b (Node a s) = c b a : f s

import Data.Char

triplos :: [Int] -> [Int]
triplos l = map (\x -> x*3) l

maiusculas :: String -> String 
maiusculas l = map (toUpper) l

somapares :: [(Int,Int)] -> [Int]
somapares l = map (\(x,y) -> x+y) l

pares :: [Int] -> [Int]
pares  = filter (\x -> mod x 2 == 0) 

positivos :: [Int] -> [Int]
positivos l = filter (\x -> x > 0) l

produto :: [Int] -> Int
produto l = foldr (*) 1 l

suma :: [Int] -> Int 
suma l = foldr (+) 0 l

concata :: [[a]] -> [a]
concata l = foldr (++) [] l 

reve :: [a] -> [a]
reve l = foldr (\x a -> a ++ [x]) [] l

le :: [a] -> Int 
le l = foldr (\x y -> 1 + y) 0 l

soma :: [Int] -> Int 
soma l = foldl (+) 0 l



type Polinomio = [Monomio]
type Monomio = (Int,Int)

pol :: Polinomio
pol = [(1,2),(3,1),(2,0),(4,0)]

selgrau :: Int -> Polinomio -> Polinomio 
selgrau n p = filter (\x -> snd x == n) p
            
conta :: Int -> Polinomio -> Int 
conta n p = length (selgrau n p)

grau :: Polinomio -> Int 
grau p = maximum $ map (\(x,y) -> y) p

deriv :: Polinomio -> Polinomio 
deriv p = filter (\(x,y) -> x /= 0) $ map (\(x,y) -> (x*y,y-1)) p

calcula :: Float -> Polinomio -> Float 
calcula a l = foldl (\ac (x,y) -> ac + (x^y)*a ) 0 l

mult :: Monomio -> Polinomio -> Polinomio 
mult (x,y) p = map (\(a,b) -> (a*x,b+y)) p

ordena :: Polinomio -> Polinomio 
ordena  = sortOn snd 

normaliza :: Polinomio -> Polinomio 
normaliza ((a,b):c) = map (\(x,y) -> if y == b then (x+a,b) else (x,y)) ((a,b):c)


type Mat a = [[a]]

mat :: Mat Int
mat = [[1,2,3],[0,4,5],[0,0,5]]

dim :: Mat a -> Bool 
dim l = length (rep (aux l)) == 1

rep :: [Int] -> [Int]
rep [] = []
rep (a:c) | a `elem` c = rep c 
          | otherwise = a : rep c

aux :: Mat a -> [Int]
aux [[]] = []
aux [] = []
aux (a:c) = length a : aux c

dimmat :: Mat a -> (Int,Int)
dimmat (m:a) = (length (m:a), length m)

transpose :: Mat a -> Mat a 
transpose ([]:_) = []
transpose mat = map head mat : transpose (map tail mat)


fib :: Int -> Int 
fib x = prim x 1 0 

prim :: Int -> Int -> Int -> Int 
prim 0 x z = z 
prim x y z = prim (x-1) (y+z) (y)

alp :: String -> (String, String)
alp [] = ([],[])
alp (a:b) | isAlpha a = (c++[a],d)
          | isDigit a = (c,d++[a])
    where (c,d) = alp b

nzp :: [Int] -> (Int,Int,Int)
nzp [] = (0,0,0)
nzp (a:b) | a > 0 = (x+1,y,z)
          | a == 0 = (x,y+1,z)
          | a < 0 = (x,y,z+1)
    where (x,y,z) = nzp b

divmod :: Integral a => a -> a -> (a,a)
divmod a b = aux a b (0,0)

aux :: Integral a => a -> a -> (a,a) -> (a,a)
aux a b (c,d) | a - b < 0 = (c,abs a)
              | a - b > 0 = aux (a-b) b (c+1,b)
              | a - b == 0 = (c+1,0)

int :: Integer -> String 
int a = ax a []

ax :: Integer -> String -> String 
ax 0 x = x 
ax x l = l ++ show x


data ExpInt = Cons Int 
            | Simetrico ExpInt 
            | Mais ExpInt 
            | Menos ExpInt 
            | Mult ExpInt 

instance Show ExpInt where 
    --show a = mostra a
    show (Cons a) = show a 
    show (Simetrico ex) = "- " ++ show ex
    show (Mais ex) = show ex ++ " + "
    show (Menos ex) = show ex ++ " - "
    show (Mult ex) = show ex ++ " * " 

--mostra :: Show a => ExpInt -> String
mostra (Cons a) = show a  
mostra (Simetrico a) = "-" ++ show a 
mostra (Mais a) = "+" ++ show a 
mostra (Menos a) = "-" ++ show a
mostra (Mult a) = "*" ++ show a

data RTree a = R a [RTree a]

rt = R 3 [R 4 [R 2 []]] 

sina :: Num a => RTree a -> a 
sina (R a []) = a
sina (R a l) = a + sum (map (sina) l)

maxi :: (Ord a) => [Maybe a] -> Maybe a 
maxi [] = Nothing 
maxi l = maxa l Nothing

maxa :: (Ord a) => [Maybe a] -> Maybe a -> Maybe a 
maxa [] c = c
maxa (a:b) c | c < a = maxa b a
             | c == a = maxa b a 
             | c > a = maxa b c 
-}


--partes :: String -> Char -> [String]
--partes [] x = []
--partes (a:b) x | a == x = partes b x ++ []
        --       | a /= x = [a] : partes b x
partes [] _ = []
partes (a:b) x | a == x = []
               | otherwise = [a] ++ partes b x

partes2 [] _ = []
partes2 (a:b) x | a == x = b
                | otherwise = partes2 b x


partes1 :: String -> Char -> [String]
partes1 [] _ = []
partes1 (a:b) x = [partes (a:b) x] ++ partes1 (partes2 (a:b) x) x