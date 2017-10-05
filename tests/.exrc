if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
vmap gx <Plug>NetrwBrowseXVis
nmap gx <Plug>NetrwBrowseX
vnoremap <silent> <Plug>NetrwBrowseXVis :call netrw#BrowseXVis()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#BrowseX(expand((exists("g:netrw_gx")? g:netrw_gx : '<cfile>')),netrw#CheckIfRemote())
let &cpo=s:cpo_save
unlet s:cpo_save
set background=dark
set backspace=indent,eol,start
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=en
set nomodeline
set path=.,/usr/include,,,~/git/c/graph/include,~/git/c/hvac/include,~/git/c/esolv/include,~/git/c/logs/include,~/git/c/esolv_python/include,~/git/hvac_python/include,~/git/thermal_design/thermal_design/include,~/backedup/git/cpp/pipe_network/include,~/git/circuiting/include
set printoptions=paper:letter
set ruler
set runtimepath=~/.vim,/var/lib/vim/addons,/usr/share/vim/vimfiles,/usr/share/vim/vim74,/usr/share/vim/vimfiles/after,/var/lib/vim/addons/after,~/.vim/after
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
" vim: set ft=vim :
