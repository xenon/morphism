#lang racket
(require "array-generator.rkt")
(require "maps.rkt")
;; this command outputs the iterated map on 20 iterations
(output_list_format (iterate_map map_h 20))
