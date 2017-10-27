set nocp
set nohls
set hid
set wmnu
set wim=full
set et
set sta
set ts=2
set sw=2
set sts=2
set cin
set cink-=0#
set indk-=0#
set wrap
set mouse=a
inoremap jk <esc>
map <S-q> :s,^,//,<cr>
map <S-e> :s,^//,<cr>

colorscheme elflord
filetype indent on
syntax on
set sc
set ls=2
set nu

map 0 ^
map j gj
map k gk
map <F5> :make<CR>
map <F6> :make all<CR>

set cino+=g0
set cino+=N-s
