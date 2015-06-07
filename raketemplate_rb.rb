#!/usr/bin/env ruby
# coding: utf-8

require "rake/clean"
CLEAN << FileList["actual*.txt"]

$script = "code.rb"

Dir.glob("expected*.txt").each do |expected|
  next unless expected =~ /expected(\d*)\.txt/
  num = $1
  actual = "actual#{num}.txt"
  testcase = "testcase#{num}.txt"

  file actual => [$script, testcase, expected] do
    if File.exist? testcase
      sh "ruby #{$script} < #{testcase} > #{actual}"
    else
      sh "ruby #{$script} > #{actual}"
    end
  end

  task :test => [actual, expected] do
    sh "diff #{actual} #{expected}" rescue nil
  end
end

task :default => :test
