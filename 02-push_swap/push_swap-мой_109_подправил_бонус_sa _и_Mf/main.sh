# make re && ./push_swap "7 64 18  99 15 12 1 33 95 11 55               "
# make && ./push_swap '-26', '-34', '-37', '3', '-3', '-124', '200', '180', '140', '-137', '109', '43', '-107', '55', '51', '111', '-74', '-95', '82', '150', '63', '40', '-61', '79', '104', '41', '191', '188', '-94', '-4', '73', '54', '-156', '-97', '183', '171', '-143', '-188', '-134', '-164', '101', '-27', '-53', '-59', '161', '-70', '-44', '15', '113', '-120', '-125', '119', '144', '38', '49', '-25', '147', '-28', '166', '-88', '-109', '112', '-135', '29', '-46', '-96', '158', '132', '94', '58', '-48', '95', '-116', '-170', '-41', '60', '-13', '-168', '-43', '199', '-179', '122', '-199', '-112', '75', '-140', '20', '110', '-132', '-165', '-73', '34', '-9', '-111', '127', '14', '120', '106', '-193', '164', '-151', '197', '153', '-84', '143', '-149', '-85', '-157', '196', '-117', '114', '-158', '-171', '-155', '-93', '16', '136', '-123', '-100', '90', '-115', '-133', '130', '100', '-178', '84', '174', '148', '-66', '108', '-36', '167', '78', '142', '173', '-10', '-87', '-175', '152', '53', '-127', '-108', '-126', '-102', '-78', '125', '44', '187', '-32', '72', '-195', '7', '116', '-6', '-163', '52', '-198', '97', '121', '30', '-77', '139', '24', '68', '160', '-71', '-139', '0', '-154', '-118', '-81', '-67', '-119', '181', '92', '-161', '-129', '-99', '-130', '80', '-15', '-101', '-83', '163', '146', '170', '-160', '93', '-7', '117', '107', '-197', '88', '177', '129', '131', '-16', '-52', '87', '-146', '-105', '-1', '145', '151', '179', '64', '50', '-191', '103', '-51', '-138', '10', '192', '11', '172', '33', '-39', '-131', '81', '47', '-57', '-35', '-103', '71', '-181', '123', '-172', '135', '48', '-89', '67', '178', '8', '5', '-56', '17', '-82', '-62', '-147', '28', '37', '-162', '-183', '157', '2', '-159', '-142', '96', '102', '-104', '138', '19', '-49', '99', '154', '-79', '-136', '168', '36', '162', '27', '175', '193', '56', '22', '83', '-144', '-182', '134', '76', '13', '-192', '-76', '-173', '61', '45', '-40', '194', '23', '-23', '-90', '32', '-24', '169', '184', '-30', '-63', '-47', '186', '85', '1', '-54', '155', '-33', '-69', '-91', '126', '182', '141', '31', '-55', '-92', '-167', '86', '57', '128', '-196', '91', '65', '-18', '-166', '-2', '115', '9', '-12', '118', '-60', '133', '74', '-152', '-148', '-29', '-17', '-174', '35', '21', '-75', '18', '-106', '59', '-186', '-8', '-11', '-194', '105', '-153', '-114', '-86', '-72', '185', '-14', '-187', '12', '4', '-145', '77', '-150', '69', '62', '-189', '-176', '6', '-80', '176', '-98', '-64', '-180', '39', '-177', '-190', '189', '190', '-5', '195', '-19', '-50', '-122', '198', '-20', '66', '89', '98', '149', '124', '-45', '-200', '159', '-185', '-42', '70', '-22', '-121', '-68', '-65', '-38', '-141', '156', '46', '-58', '25', '-21', '165', '-110', '-184', '42', '-128', '26', '-169', '-113', '137', '-31'
# make && ./push_swap  "3 22 66 51 35 70 99 60 30 13 21 54 34 89 85 47 49 5 77 80 39 12 25 74 52 53 83 62 73 98 36 24 59 37 42 68 4 7 26 97 58 67 79 94 69 48 17 0 40 8 41 45 28 76 84 50 88 19 82 65 56 92 81 29 71 9 86 61 55 6 64 11 46 63 1 75 38 2 72 93 27 33 44 15 18 23 43 57 87 14 20 90 32 91 78 10 95 16 96 31"
# make && ./push_swap  "100 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1  0   "
# make && ./push_swap  "30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1  0   "
# make re && ./push_swap "37 35 4 25 93 18 40 11 38 20 27 94 28 50 41 45 52 54 39 16 34 98 8 62 71 22 95 13 2 69 88 0 73 51 59 64 6 48 14 67 12 83 72 90 80 30 84 21 89 61 66 99 55 56 43 97 9 87 70 96 49 76 33 36 92 17 65 7 75 15 86 58 42 74 81 32 31 3 47 79 53 68 24 1 5 82 46 91 63 29 78 77 10 60 44 23 26 57 19 85"
# make re && ./push_swap  0 3 2 1 4 20
# make && leaks --atExit --  ./push_swap 7 64 18  99 15 11 14 19 58 96
# make && valgrind --leak-check=full --show-leak-kinds=all -s ./push_swap 7 64 18  99 15 12 1 33 95 11
# make && valgrind --leak-check=full --show-leak-kinds=all -s ./push_swap 7 64 18  99 
# make && valgrind --leak-check=full --show-leak-kinds=all ./push_swap 7 64 18  99 15 12 1 33 95 11
# make && ./push_swap "315 342 90 287 289 415 133 450 332 439 310 237 175 191 179 23 396 318 264 469 73 359 220 64 374 153 414 76 221 212 286 40 498 80 12 326 187 127 313 84 18 426 5 168 208 107 192 26 362 269 236 418 373 246 348 387 122 109 53 427 394 135 63 79 265 170 338 100 143 209 491 8 166 172 273 364 41 75 145 250 243 490 475 425 375 343 87 102 281 486 448 292 323 248 422 293 388 280 263 183 210 180 129 196 401 260 136 132 128 363 306 3 137 16 366 201 77 445 275 256 251 309 357 368 371 367 151 481 410 17 312 240 472 0 97 74 188 487 325 244 131 386 193 211 284 230 328 471 447 156 169 228 416 467 103 159 57 459 59 165 242 352 443 130 50 319 389 198 392 98 52 385 382 252 206 377 235 298 436 346 22 409 453 82 203 38 438 405 333 33 207 390 433 123 44 492 15 279 245 423 474 407 214 478 47 278 31 7 322 225 254 110 81 43 295 36 499 294 430 307 104 383 406 229 55 482 316 493 9 160 233 152 134 402 398 420 380 308 70 249 285 302 215 337 454 311 354 314 204 458 479 399 372 429 121 391 96 163 449 241 60 431 317 334 347 441 356 463 32 403 331 139 274 470 141 468 217 30 226 2 384 238 477 19 94 112 268 69 335 213 378 483 113 195 174 89 150 1 351 157 65 184 341 239 296 148 88 224 186 457 361 262 124 182 199 451 54 34 48 232 25 299 353 86 304 442 45 488 247 126 154 496 173 344 485 234 200 197 83 349 58 4 253 283 56 464 117 412 267 397 424 181 421 305 162 190 118 67 140 116 369 381 266 370 105 432 473 20 42 106 437 393 257 10 329 185 355 119 411 365 28 149 71 21 466 321 336 189 194 460 14 101 35 178 419 61 270 39 440 164 340 455 497 489 205 68 330 223 99 72 177 219 138 66 46 111 350 27 320 480 495 404 255 339 11 93 288 408 222 144 376 147 324 114 476 258 216 115 417 142 301 231 218 358 446 161 37 300 202 171 92 291 435 428 465 85 345 327 6 277 125 395 91 120 494 95 158 456 461 108 297 13 51 462 272 379 24 78 259 276 176 155 167 146 400 62 49 452 434 484 413 360 290 444 271 29 303 282 227 261"
# make && ./push_swap    1 4 2 3 0   
# make re && leaks --atExit --  ./push_swap "315 342 90 287 289 415 133 450 332 439 310 237 175 191 179 23 396 318 264 469 73 359 220 64 374 153 414 76 221 212 286 40 498 80 12 326 187 127 313 84 18 426 5 168 208 107 192 26 362 269 236 418 373 246 348 387 122 109 53 427 394 135 63 79 265 170 338 100 143 209 491 8 166 172 273 364 41 75 145 250 243 490 475 425 375 343 87 102 281 486 448 292 323 248 422 293 388 280 263 183 210 180 129 196 401 260 136 132 128 363 306 3 137 16 366 201 77 445 275 256 251 309 357 368 371 367 151 481 410 17 312 240 472 0 97 74 188 487 325 244 131 386 193 211 284 230 328 471 447 156 169 228 416 467 103 159 57 459 59 165 242 352 443 130 50 319 389 198 392 98 52 385 382 252 206 377 235 298 436 346 22 409 453 82 203 38 438 405 333 33 207 390 433 123 44 492 15 279 245 423 474 407 214 478 47 278 31 7 322 225 254 110 81 43 295 36 499 294 430 307 104 383 406 229 55 482 316 493 9 160 233 152 134 402 398 420 380 308 70 249 285 302 215 337 454 311 354 314 204 458 479 399 372 429 121 391 96 163 449 241 60 431 317 334 347 441 356 463 32 403 331 139 274 470 141 468 217 30 226 2 384 238 477 19 94 112 268 69 335 213 378 483 113 195 174 89 150 1 351 157 65 184 341 239 296 148 88 224 186 457 361 262 124 182 199 451 54 34 48 232 25 299 353 86 304 442 45 488 247 126 154 496 173 344 485 234 200 197 83 349 58 4 253 283 56 464 117 412 267 397 424 181 421 305 162 190 118 67 140 116 369 381 266 370 105 432 473 20 42 106 437 393 257 10 329 185 355 119 411 365 28 149 71 21 466 321 336 189 194 460 14 101 35 178 419 61 270 39 440 164 340 455 497 489 205 68 330 223 99 72 177 219 138 66 46 111 350 27 320 480 495 404 255 339 11 93 288 408 222 144 376 147 324 114 476 258 216 115 417 142 301 231 218 358 446 161 37 300 202 171 92 291 435 428 465 85 345 327 6 277 125 395 91 120 494 95 158 456 461 108 297 13 51 462 272 379 24 78 259 276 176 155 167 146 400 62 49 452 434 484 413 360 290 444 271 29 303 282 227 261"
# make &&  ./push_swap "315 342 90 287 289 415 133 450 332 439 310 237 175 191 179 23 "
# make re && leaks --atExit --  ./push_swap "315 342 90 287 289 415 133 450 332 439 310 237 175 191 179 23 "
# make re && valgrind --leak-check=full --show-leak-kinds=all -s ./push_swap "315 342 90 287 289 415 133 450 332 439 310 237 175 191 179 23 "
# make re && valgrind --leak-check=full --show-leak-kinds=all ./push_swap "315 342 90 287 289 415 133 450 332 439 310 237 175 191 179 23 396 318 264 469 73 359 220 64 374 153 414 76 221 212 286 40 498 80 12 326 187 127 313 84 18 426 5 168 208 107 192 26 362 269 236 418 373 246 348 387 122 109 53 427 394 135 63 79 265 170 338 100 143 209 491 8 166 172 273 364 41 75 145 250 243 490 475 425 375 343 87 102 281 486 448 292 323 248 422 293 388 280 263 183 210 180 129 196 401 260 136 132 128 363 306 3 137 16 366 201 77 445 275 256 251 309 357 368 371 367 151 481 410 17 312 240 472 0 97 74 188 487 325 244 131 386 193 211 284 230 328 471 447 156 169 228 416 467 103 159 57 459 59 165 242 352 443 130 50 319 389 198 392 98 52 385 382 252 206 377 235 298 436 346 22 409 453 82 203 38 438 405 333 33 207 390 433 123 44 492 15 279 245 423 474 407 214 478 47 278 31 7 322 225 254 110 81 43 295 36 499 294 430 307 104 383 406 229 55 482 316 493 9 160 233 152 134 402 398 420 380 308 70 249 285 302 215 337 454 311 354 314 204 458 479 399 372 429 121 391 96 163 449 241 60 431 317 334 347 441 356 463 32 403 331 139 274 470 141 468 217 30 226 2 384 238 477 19 94 112 268 69 335 213 378 483 113 195 174 89 150 1 351 157 65 184 341 239 296 148 88 224 186 457 361 262 124 182 199 451 54 34 48 232 25 299 353 86 304 442 45 488 247 126 154 496 173 344 485 234 200 197 83 349 58 4 253 283 56 464 117 412 267 397 424 181 421 305 162 190 118 67 140 116 369 381 266 370 105 432 473 20 42 106 437 393 257 10 329 185 355 119 411 365 28 149 71 21 466 321 336 189 194 460 14 101 35 178 419 61 270 39 440 164 340 455 497 489 205 68 330 223 99 72 177 219 138 66 46 111 350 27 320 480 495 404 255 339 11 93 288 408 222 144 376 147 324 114 476 258 216 115 417 142 301 231 218 358 446 161 37 300 202 171 92 291 435 428 465 85 345 327 6 277 125 395 91 120 494 95 158 456 461 108 297 13 51 462 272 379 24 78 259 276 176 155 167 146 400 62 49 452 434 484 413 360 290 444 271 29 303 282 227 261"
# make && ./push_swap "315 342 90 287 289 415 133 450 332 439 310 237 175 191 179 23 396 318 264 469 73 359 220 64 374 153 414 76 221 212 286 40 498 80 12 326 187 127 313 84 18 426 5 168 208 107 192 26 362 269 236 418 373 246 348 387 122 109 53 427 394 135 63 79 265 170 338 100 143 209 491 8 166 172 273 364 41 75 145 250 243 490 475 425 375 343 87 102 281 486 448 292 323 248 422 293 388 280 263 183 210 180 129 196 401 260 136 132 128 363 306 3 137 16 366 201 77 445 275 256 251 309 357 368 371 367 151 481 410 17 312 240 472 0 97 74 188 487 325 244 131 386 193 211 284 230 328 471 447 156 169 228 416 467 103 159 57 459 59 165 242 352 443 130 50 319 389 198 392 98 52 385 382 252 206 377 235 298 436 346 22 409 453 82 203 38 438 405 333 33 207 390 433 123 44 492 15 279 245 423 474 407 214 478 47 278 31 7 322 225 254 110 81 43 295 36 499 294 430 307 104 383 406 229 55 482 316 493 9 160 233 152 134 402 398 420 380 308 70 249 285 302 215 337 454 311 354 314 204 458 479 399 372 429 121 391 96 163 449 241 60 431 317 334 347 441 356 463 32 403 331 139 274 470 141 468 217 30 226 2 384 238 477 19 94 112 268 69 335 213 378 483 113 195 174 89 150 1 351 157 65 184 341 239 296 148 88 224 186 457 361 262 124 182 199 451 54 34 48 232 25 299 353 86 304 442 45 488 247 126 154 496 173 344 485 234 200 197 83 349 58 4 253 283 56 464 117 412 267 397 424 181 421 305 162 190 118 67 140 116 369 381 266 370 105 432 473 20 42 106 437 393 257 10 329 185 355 119 411 365 28 149 71 21 466 321 336 189 194 460 14 101 35 178 419 61 270 39 440 164 340 455 497 489 205 68 330 223 99 72 177 219 138 66 46 111 350 27 320 480 495 404 255 339 11 93 288 408 222 144 376 147 324 114 476 258 216 115 417 142 301 231 218 358 446 161 37 300 202 171 92 291 435 428 465 85 345 327 6 277 125 395 91 120 494 95 158 456 461 108 297 13 51 462 272 379 24 78 259 276 176 155 167 146 400 62 49 452 434 484 413 360 290 444 271 29 303 282 227 261"
# make re && ./push_swap "315 342 90 287 289 415 133 450 332 439 310 237 175 191 179 23 396 318 264 469 73 359 220 64 374 153 414 76 221 212 286 40 498 80 12 326 187 127 313 84 18 426 5 168 208 107 192 26 362 269 236 418 373 246 348 387 122 109 53 427 394 135 63 79 265 170 338 100 143 209 491 8 166 172 273 364 41 75 145 250 243 490 475 425 375 343 87 102 281 486 448 292 323 248 422 293 388 280 263 183 210 180 129 196 401 260 136 132 128 363 306 3 137 16 366 201 77 445 275 256 251 309 357 368 371 367 151 481 410 17 312 240 472 0 97 74 188 487 325 244 131 386 193 211 284 230 328 471 447 156 169 228 416 467 103 159 57 459 59 165 242 352 443 130 50 319 389 198 392 98 52 385 382 252 206 377 235 298 436 346 22 409 453 82 203 38 438 405 333 33 207 390 433 123 44 492 15 279 245 423 474 407 214 478 47 278 31 7 322 225 254 110 81 43 295 36 499 294 430 307 104 383 406 229 55 482 316 493 9 160 233 152 134 402 398 420 380 308 70 249 285 302 215 337 454 311 354 314 204 458 479 399 372 429 121 391 96 163 449 241 60 431 317 334 347 441 356 463 32 403 331 139 274 470 141 468 217 30 226 2 384 238 477 19 94 112 268 69 335 213 378 483 113 195 174 89 150 1 351 157 65 184 341 239 296 148 88 224 186 457 361 262 124 182 199 451 54 34 48 232 25 299 353 86 304 442 45 488 247 126 154 496 173 344 485 234 200 197 83 349 58 4 253 283 56 464 117 412 267 397 424 181 421 305 162 190 118 67 140 116 369 381 266 370 105 432 473 20 42 106 437 393 257 10 329 185 355 119 411 365 28 149 71 21 466 321 336 189 194 460 14 101 35 178 419 61 270 39 440 164 340 455 497 489 205 68 330 223 99 72 177 219 138 66 46 111 350 27 320 480 495 404 255 339 11 93 288 408 222 144 376 147 324 114 476 258 216 115 417 142 301 231 218 358 446 161 37 300 202 171 92 291 435 428 465 85 345 327 6 277 125 395 91 120 494 95 158 456 461 108 297 13 51 462 272 379 24 78 259 276 176 155 167 146 400 62 49 452 434 484 413 360 290 444 271 29 303 282 227 261"          
# make re &&  ./push_swap "462 274 157 11 251 124 281 21 486 149 244 493 263 394 401 105 472 203 44 338 454 468 196 358 471 252 166 487 49 184 35 296 112 71 226 8 307 88 125 153 38 315 255 16 353 369 185 271 354 427 115 174 193 42 455 269 93 318 277 356 40 317 421 325 108 230 417 91 59 461 198 324 96 227 349 377 477 259 90 79 248 448 245 147 331 180 337 23 332 176 287 258 74 301 246 201 484 10 138 273 34 314 36 130 132 143 181 408 411 213 390 494 464 366 399 216 0 450 225 466 13 61 82 485 397 48 104 232 222 309 118 114 415 142 490 139 312 146 87 267 210 75 453 205 27 195 206 499 446 253 81 385 217 444 479 433 46 175 24 400 342 63 200 320 179 423 362 129 420 436 412 467 328 272 155 275 470 55 491 285 367 102 475 77 438 290 334 204 19 188 313 72 15 100 215 445 161 481 374 250 103 456 376 64 41 89 449 300 67 164 347 233 302 410 260 310 20 107 348 382 144 57 413 428 234 228 321 9 190 120 95 319 70 30 476 437 173 165 178 14 109 84 47 54 288 154 465 335 497 361 187 186 330 247 291 254 99 404 237 323 355 192 111 25 371 239 426 126 256 26 452 264 419 372 295 221 495 469 231 101 294 183 106 279 422 7 329 447 83 119 389 418 220 128 150 45 268 373 441 365 197 458 378 478 136 78 440 482 238 177 266 156 243 235 306 39 65 463 199 344 305 113 407 43 322 141 262 12 280 403 405 86 169 370 442 62 311 85 219 97 299 167 308 172 435 202 379 211 261 340 351 18 286 368 122 33 191 346 207 137 69 92 32 168 364 416 326 131 249 223 391 152 460 182 2 424 159 50 406 242 28 1 56 194 135 158 393 241 360 336 73 395 270 398 387 439 189 339 209 498 5 282 134 3 236 60 145 148 298 345 151 431 240 480 94 304 98 116 443 110 80 289 218 496 17 425 163 283 229 343 224 292 276 341 459 429 357 483 51 451 414 293 257 52 489 350 208 214 297 375 488 474 53 327 383 434 29 396 22 127 388 171 359 492 133 430 212 121 352 409 402 284 66 6 278 160 76 384 123 37 381 68 58 363 316 162 170 333 31 473 140 4 380 457 392 432 117 386 303 265"
# make re && ./push_swap  "10 24 1 8 90 37 81 82 32 51 53 61 66 80 67 21 5 34 75 3 84 39 2 59 36 95 7 73 63 6 87 64 33 49 55 19 35 77 88 27 52 43 62 15 44 26 45 48 79 83 20 40 13 98 56 12 74 97 18 54 42 65 28 47 57 16 70 17 9 14 58 69 22 0 72 92 29 38 11 89 96 78 41 71 50 46 4 76 86 91 30 60 68 23 94 93 99 31 85 25"
# make re && ./push_swap "5 8 4 3"
make && ./push_swap  2 0 1 45

#====len_a = 3
#s_a[0] = 18
#s_a[1] = 99
#s_a[2] = 1
#====len_b = 7
#s_b[0] = 11
#s_b[1] = 95
#s_b[2] = 33
#s_b[3] = 12
#s_b[4] = 15
#s_b[5] = 64
#s_b[6] = 7
#========