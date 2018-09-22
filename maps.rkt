#lang racket
(provide (all-defined-out))

;; the example mapping without cubes
(define (map_h num)
  (cond
    [(equal? num 0) (list 0 3)]
    [(equal? num 1) (list 4 3)]
    [(equal? num 3) (list 1)]
    [(equal? num 4) (list 0 1)]))

(define (map_test num)
  (cond
  	[(equal? num 0) (list 3 2)]
  	[(equal? num 1) (list 0)]
  	[(equal? num 2) (list 0 2)]
  	[(equal? num 3) (list 3 1)]))
