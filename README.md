# knotebook

Program that will be used to store throwaway-code for kata exercises/ideas. Programs are stored with the name and programming language.

## Usage

With curl:
	- `curl -X POST --data 'name=[program_name]&lang=[language]&code='"$(cat [filename])"'' localhost:1234/create`

## Tasks
- [ ] fix parser to read code and ignore `&` (in languages like c/c++)
- [ ] make data easier to query 
- [x] ~~async server base~~
- [x] ~~parser that can parse url-format variables, get correct parameters and code~~
- [x] ~~store data in binary form~~
- [x] ~~create client program for creating entries~~
