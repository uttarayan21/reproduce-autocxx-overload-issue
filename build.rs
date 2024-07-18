use std::path::{Path};
const VENDOR: &str = concat!(env!("CARGO_MANIFEST_DIR"), "/vendor");
type Result<T, E= Box<dyn std::error::Error>> = std::result::Result<T, E>;

fn main() -> Result<()> {
    build_bindings(VENDOR)?;
    Ok(())
}

pub fn build_bindings(path: impl AsRef<Path>) -> Result<()> {
    let inc_path = path.as_ref();
    let mut builder = autocxx_build::Builder::new("src/main.rs", &[&inc_path]).build()?;
    builder
        .file("vendor/demo.cpp")
        .std("c++14")
        .compile("autocxx-bridge");
    println!("cargo:rerun-if-changed=src/main.rs");
    println!("cargo:rustc-link-lib=autocxx-bridge");

    Ok(())
}

