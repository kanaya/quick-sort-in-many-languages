(use srfi-1)
(use data.random)
(use gauche.generator)

(define (quick-sort f ls)
	(if (null? ls)
		'()
		(let ([x (car ls)]
		      [xs (cdr ls)])
			(let ([before (quick-sort f (filter (lambda (y) ((compose not f) x y)) xs))]
			      [after (quick-sort f (filter (lambda (y) (f x y)) xs))])
				(append before (cons x after))))))

(define (main args)
	(let ([random-numbers (generator->list (integers$ 100 0) 100)])
		(print (quick-sort < random-numbers))))