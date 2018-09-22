#lang racket
(provide (all-defined-out))

;; basic induction to represent recursion
(define (iterate_map map_name num_times)
  (cond
    [(equal? num_times 0) '(0)]
    [else (append-map map_name (iterate_map map_name (- num_times 1)))]))

;;(display (iterate_map map_h 20) (current-output-port))

(define (output_list_format lst)
  (begin (display (length lst) (current-output-port))
  		 (display "\n" (current-output-port))
  		 (output_list_format2 lst)))

(define (output_list_format2 lst)
  (cond
  	[(empty? lst) (display "\n" (current-output-port))]
  	[else (begin (display (first lst) (current-output-port))
  				 ;;(display " " (current-output-port))
  				 (output_list_format2 (rest lst)))]))
