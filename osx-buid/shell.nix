let
  nixpkgs = fetchTarball "https://github.com/NixOS/nixpkgs/tarball/nixos-24.11";
  pkgs = import nixpkgs { config = {}; overlays = []; };
in

pkgs.mkShellNoCC {
  buildInputs = [pkgs.apple-sdk_15];
  packages = with pkgs; [    
    ccache 
    cmake
    gcc
    git 
    libvorbis
    llvm 
    libdevil
    freetype
    ninja 
    python3
    SDL2
    socat
    xorg.xorgproto
    xorg.libXcursor
    xorg.libXrender
    xorg.libXv
    xorg.libXfixes
    xz
    pkgconf
    curl
    p7zip
    fontconfig
    expat
    zsh
  ];
  shellHook = ''    
    export SHELL="${pkgs.zsh}/bin/zsh"
    exec zsh
  '';
}