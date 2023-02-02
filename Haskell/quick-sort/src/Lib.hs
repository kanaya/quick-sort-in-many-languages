module Lib
    ( someFunc
    ) where

quickSort :: Ord a => [a] -> [a]
quickSort [] = []
quickSort [x] = [x]
quickSort (x:xs) = quickSort left ++ [x] ++ quickSort right
    where left  = filter (<  x) xs
          right = filter (>= x) xs

someFunc :: IO ()
someFunc = print $ quickSort [1, 8, 7, 6, 2, 5, 9, 4, 0, 3]

