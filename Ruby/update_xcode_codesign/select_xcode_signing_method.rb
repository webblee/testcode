#!/usr/bin/ruby

require 'xcodeproj'

# Usage:
# ruby select_xcode_signing_method.rb -p <path/to/xcode_project> -t <Target> -m ['Automatic' | 'Manual']

class Options
  attr_accessor :path, :target, :method

  def initialize(args)
    @path = args[:path] || Dir.glob("*.xcodeproj").first
    @target = args[:target]
    @method = args[:method]
  end
end

def parse_args
  options_hash = {}
  args = ARGV
  args.each_with_index do |arg, index|
    case arg
    when '--project_path', '-p'
      path = args[index + 1]
      unless File.exist?(path)
        abort('There is no file at specified path.')
      end
      options_hash[:path] = path
    when '--target', '-t'
      options_hash[:target] = args[index + 1]
    when '--signing_method', '-m'
      method = args[index + 1]
      unless ['Automatic', 'Manual'].include?(method)
        abort("'Invalid signing method specified. Please use either 'Automatic' or 'Manual'")
      end
      options_hash[:method] = method
    end
  end

  options_hash
end

options = Options.new parse_args

puts "path: '#{options.path}'.\n"
puts "target: '#{options.target}'.\n"
puts "method: '#{options.method}'.\n"

project = Xcodeproj::Project.open(options.path)

target_id = project.targets.select {|target| target.name == options.target }.first.uuid
attributes = project.root_object.attributes['TargetAttributes']
target_attributes = attributes[target_id]

if target_attributes == nil
  provision_attributes = Hash['ProvisioningStyle' => options.method]
  attributes[target_id] = provision_attributes
else
  target_attributes['ProvisioningStyle'] = options.method
end

project.save

puts "Code signing was set to '#{options.method}'."
