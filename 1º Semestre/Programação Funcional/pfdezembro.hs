-- Programações Dezembro

import System.Random
import Data.Char
import Data.List
import qualified Data.Text as Text
import Control.Monad

-- O "data" define um tipo novo enquanto o type apenas iguala tipos

type A = Int
data B = Amaria | Oalberto 
 --   deriving Show

soma :: A -> A -> A 
soma x y = x + y

quem :: A -> B 
quem x | x < 0 = Amaria 
       | x > 0 = Oalberto  
       
instance Show B where 
    show (Amaria) = "Amaria" ++ " mt " ++ "feia"
    show (Oalberto) = "Obertinho" ++ " feio" 



umdado :: IO Int
umdado = do x <- randomRIO (1,6)
            return x
   

getl :: IO String
getl = do 
    x <- getChar 
    if (x == '\n')
    then return " "
    else do 
        xs <- getl
        return (x:xs)
   
{-
baralha :: [a] -> IO  [a]
baralha [] = return []
baralha l = do 
    x <- randomRIO (0,length l -1)
    let e = l !! x 
        r <- baralha (delete e l)
    return e : r
    -}          
  
getline = do x <- getChar 
             if x == '\n' then return []
             else do 
                y <- getline 
                return (x:y)

{- 
sequence :: [IO a] -> IO [a]
sequence [] = return []
sequence (h:t) = do 
                 x <- h
                 s <- sequence t
                 return (x:s) 
                 -}

