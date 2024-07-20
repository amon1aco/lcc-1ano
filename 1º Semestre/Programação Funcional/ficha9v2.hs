-- Ficha 9 v2

import System.Random 
import Data.Char 

--1
--a
bingo :: IO ()
bingo = do 
           putStrLn ("Vamos jogar bingo! Prime uma tecla para iniciar o Jogo!")
           nl <- acumulador []
           print nl


acumulador :: [Int] -> IO [Int]
acumulador l | length l == 90 = do 
                                return l
             | otherwise = do v <- randomRIO (1,90)
                              print v
                              getChar
                              let nl = if v `elem` l then l else v:l in acumulador nl
        
--b
mastermind :: IO ()
mastermind = do (n1,n2,n3,n4) <- getkey
                doguess (n1,n2,n3,n4)
                return ()

getkey :: IO (Int,Int,Int,Int)
getkey = do a <- randomRIO(1,9)
            b <- randomRIO (1,9)
            c <- randomRIO (1,9)
            d <- randomRIO (1,9)  
            return (a,b,c,d)

getguess :: IO (Int,Int,Int,Int)
getguess = do x <- getLine 
              if length x /= 4 || not (all isDigit x)
              then getguess
              else return (let (a:b:c:d:resto) = x in (read [a], read [b], read [c], read [d]))

doguess :: (Int,Int,Int,Int) -> IO ()
doguess (n1,n2,n3,n4) = do 
        let listaNums = [n1,n2,n3,n4] 
        (g1,g2,g3,g4) <- getguess
        let numsc = 0 + (if n1 == g1 then 1 else 0) + (if n2 == g2 then 1 else 0) + (if n3 == g3 then 1 else 0) + (if n4 == g4 then 1 else 0)
        let numss = 0 + (if n1 /= g1 && g1 `elem` (listaNums \\ [g2,g3,g4]) then 1 else 0) +
                     (if n2 /= g2 && g2 `elem` (listaNums \\ [g3,g4]) then 1 else 0) +
                     (if n3 /= g3 && g3 `elem` (listaNums \\ [g4]) then 1 else 0) +
                     (if n4 /= g4 && g4 `elem` (listaNums \\ []) then 1 else 0) 
        if numsc == 4 then print "Ganhaste" else print $ "Valores corretos: " ++ show numsc ++ " Valores no sitio errado: " ++ show numss
        if numsc == 4 then return () else doguess (n1,n2,n3,n4)