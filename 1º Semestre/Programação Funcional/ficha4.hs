-- Ficha 4

import Data.Char (isDigit, isAlpha)
import Distribution.Simple.Utils (xargs)

--1
separa :: String -> (String,String)
separa "" = ("","")
separa (x:y) = aux (x:y) ("","")
    where aux :: String -> (String,String) -> (String,String)
          aux "" (a,b) = (a,b)
          aux (x:y) (a,b) | isAlpha x = aux y (a++[x],b)
                          | isDigit x = aux y (a,b++[x])

--2
nzp :: [Int] -> (Int,Int,Int)
nzp [] = (0,0,0) 
nzp (x:y) = aux1 (x:y) (0,0,0)

aux1 :: [Int] -> (Int,Int,Int) -> (Int,Int,Int)
aux1 [] (a,b,c) = (a,b,c)
aux1 (x:y) (a,b,c) | x < 0 = aux1 y (a+1,b,c)
                   | x == 0 = aux1 y (a,b+1,c)
                   | x > 0 = aux1 y (a,b,c+1)

--3
divmod :: Integral a => a -> a -> (a,a) 
divmod x y = aj (0,0) x y

aj :: Ord a => Num a => (a,a) -> a -> a -> (a,a)
aj (a,b) x y | x - y < 0 = (a,x)
             | x - y > 0 = aj (a+1,b) (x-y) y
             | x - y == 0 = (a+1,0)

--4
fromdigits :: [Int] -> Int
fromdigits [] = 0
fromdigits (h:t) = calcula n (h:t)
       where n = length t 

calcula :: Int -> [Int] -> Int
calcula _ [] = 0 
calcula x (a:b) = a*10^x + calcula (x-1) b

--5
maxsuminit :: (Num a, Ord a) => [a] -> a 
maxsuminit (h:t) = maxaux t h h 

maxaux :: (Num a, Ord a) => [a] -> a -> a -> a 
maxaux [] _ x = x 
maxaux (h:t) x y = maxaux t x (if (h+y) > x then (h+y) else x)

--6
fib :: Int -> Int 
fib 0 = 0 
fib 1 = 1 
fib n = fib (n-1) + fib (n-2)

primfib :: Int -> Int 
primfib x = fibaux x 0 1

fibaux :: Int -> Int -> Int -> Int 
fibaux 0 n _ = n 
fibaux x y z = fibaux (x-1) (z) (y+z)
--7
int2str :: Integer -> String
int2str x = junta x ""

junta :: Integer -> String -> String 
junta x "" = show x 

--8
    --a
-- [6,12,18]
    --b
-- [6,12,18]
    --c
-- [(10,20),(11,19),(12,18),(13,17),(14,16),(15,15),(16,14),(17,13),(18,12),(19,11),(20,10)] , n falta agr o simetrico??
    --d
-- [1,1,4,4,9,9,16,16,25,25], n percebi..

--9
    --a
-- [2^x | x <- [1..10]]
    --b
-- [(x,y) | x <- [1..5], y <- [1..5], x+y == 6]
    --c
-- [ [1..x] | x <- [1..5] ]
    --d
-- [ [1 | x <- [1..y]] | y <- [1..5]]
    --e
-- [ product [y | y <- [1..x]] | x <- [1..6]]