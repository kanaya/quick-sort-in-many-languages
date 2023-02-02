(use srfi-1)

(define (quick-sort f ls)
	(if (null? ls)
		'()
		(let ([x (car ls)]
		      [xs (cdr ls)])
			(let ([before (quick-sort f (filter (lambda (y) ((compose not f) x y)) xs))]
			      [after (quick-sort f (filter (lambda (y) (f x y)) xs))])
				(append before (cons x after))))))

(define (main args)
	(print (quick-sort < '(3 5 7 2 1 10))))