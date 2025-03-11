if [ -f ~/.bash_aliases ]; then
    . ~/.bash_aliases
fi

if [ -f /etc/bashrc ]; then
    . /etc/bashrc
fi

if [ -f ~/aliases.zsh ]; then
    . ~/aliases.zsh
fi

if [ -f /etc/zshrc ]; then
    . /etc/zshrc
fi

export BAT_THEME="Catppuccin Latte"

export FZF_DEFAULT_OPTS=" \
--color=bg+:#ccd0da,bg:#eff1f5,spinner:#dc8a78,hl:#d20f39 \
--color=fg:#4c4f69,header:#d20f39,info:#8839ef,pointer:#dc8a78 \
--color=marker:#7287fd,fg+:#4c4f69,prompt:#8839ef,hl+:#d20f39 \
--color=selected-bg:#bcc0cc \
--color=border:#ccd0da,label:#4c4f69"

if [[ "$TERM_PROGRAM" != *"Apple_Terminal"* ]]; then
  eval "$(starship init zsh)"
fi

