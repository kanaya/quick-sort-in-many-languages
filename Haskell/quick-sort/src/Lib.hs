module Lib
    ( someFunc
    ) where

import System.Random

quickSort :: Ord a => [a] -> [a]
quickSort [] = []
quickSort [x] = [x]
quickSort (x:xs) = quickSort left ++ [x] ++ quickSort right
    where left  = filter (<  x) xs
          right = filter (>= x) xs

generateRandomList :: Int -> IO [Int]
generateRandomList n = sequence $ replicate n $ randomRIO (1, 100)

someFunc :: IO ()
someFunc = (quickSort <$> generateRandomList 100) >>= print

