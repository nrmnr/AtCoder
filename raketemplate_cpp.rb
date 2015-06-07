#!/usr/bin/env ruby
# coding: utf-8

require "rake/clean"
CLOBBER << "code.out"
CLOBBER << FileList["actual*.txt"]

def is_win?
  return !!(RUBY_PLATFORM =~ /mswin(?!ce)|mingw|cygwin|bccwin/)
end

if is_win?
  $ext = ".exe"
  $exe = "code.exe"
  $pre = ""
else
  $ext = ".out"
  $exe = "code.out"
  $pre = "./"
end

if File.exist? "code.cpp"
  rule $ext => [".cpp"] do |t|
    sh "g++ #{t.source} -o #{t.name}"
  end
elsif File.exist? "code.c"
  rule $ext => [".c"] do |t|
    sh "gcc #{t.source} -o #{t.name}"
  end
else
  exit
end

Dir.glob("expected*.txt").each do |expected|
  next unless expected =~ /expected(\d*)\.txt/
  num = $1
  actual = "actual#{num}.txt"
  testcase = "testcase#{num}.txt"

  file actual => $exe do
    if File.exist? testcase
      sh "#{$pre}#{$exe} < #{testcase} > #{actual}"
    else
      sh "#{$pre}#{$exe} > #{actual}"
    end
  end

  task :test => [actual, expected] do
    sh "diff #{actual} #{expected}" rescue nil
  end
end

task :default => :test
