(use srfi-1)
(use data.random)
(use gauche.generator)

(define (quick-sort ls)
	(if (null? ls)
		'()
		(let ([x (car ls)]
		      [xs (cdr ls)])
			(let ([left (quick-sort (filter (lambda (y) (< y x)) xs))]
			      [right (quick-sort (filter (lambda (y) (>= y x)) xs))])
				(append left (cons x right))))))

(define (main args)
	(let ([random-numbers (generator->list (integers$ 100 0) 100)])
		(print (quick-sort random-numbers))))